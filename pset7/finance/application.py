import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    #Query stocks and numbers of shares combined for the user
    stocks = db.execute("SELECT Stock, SUM(`Number of Shares`) FROM transactions WHERE ID = :ID GROUP BY Stock", ID = session["user_id"])

    #Select cash to be used later
    cash = db.execute("SELECT cash FROM users where ID = :ID", ID = session["user_id"])

    #Declare a list to hold dictionaries to be passed to index.html
    mylist = []

    #Initialize a grand total
    grandtotal = 0

    #Iterate through stocks for information to be added to mylist
    for i in stocks:

        quote = lookup(i['Stock'])

        if quote == None:
            return apology("Input proper stock symbol", 400)

        numberofshares = i['SUM(`Number of Shares`)']

        mydict = {'symbol' : quote['symbol'], 'stockname' : quote['name'], 'numofshares' : numberofshares, 'currentprice' : quote['price'] , 'total' : round(numberofshares*quote['price'], 2)}

        grandtotal += mydict["total"]

        mylist.append(mydict)

    return render_template("index.html", mylist = mylist, cash = round(cash[0]["cash"], 2), grandtotal = round(grandtotal + cash[0]["cash"], 2))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    #Import time module for transaction table
    from time import gmtime, strftime

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure symbol was submitted
        if not request.form.get("symbol"):
            return apology("must provide stock symbol", 400)

        # Ensure shares was submitted
        if not request.form.get("shares"):
            return apology("must provide number of shares", 400)

        # Ensure shares is numeric
        if not request.form.get("shares").isnumeric():
            return apology("Must be numeric", 400)

        # Ensure shares is an integer
        if not float(request.form.get("shares")).is_integer():
            return apology("Must be an integer", 400)

        quote = lookup(request.form.get("symbol"))

        if quote == None:
            return apology("Input proper stock symbol", 400)

        if int(request.form.get("shares")) <= 0:
            return apology("Shares must be one or greater")

        rows = db.execute("SELECT cash FROM users WHERE id = :id", id = session["user_id"])

        #Calculate the total price of the stocks at the the current price
        sharescost = int(request.form.get("shares")) * quote['price']
        time = strftime("%a, %d %b %Y %H:%M:%S +0000", gmtime())

        if (rows[0]["cash"] < sharescost):
            return apology("Not enough cash", 400)
        else:
            #If transaction is able to go through, insert appropriate info into transactions database
            db.execute("INSERT INTO transactions VALUES (:id, :stock, :stockprice, :numofshares, :time)", id = session["user_id"], stock = request.form.get("symbol"), stockprice = quote['price'], numofshares = request.form.get("shares"), time = time)
            #Update cash after purchase
            db.execute("UPDATE users SET cash = cash - (:sharescost) WHERE id = :id", sharescost = sharescost, id = session["user_id"])

            return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    #Query complete history of transactions to be passed to history.html
    history = db.execute("SELECT * FROM transactions WHERE ID = :ID", ID = session["user_id"])

    return render_template("history.html", history = history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":

        quote = lookup(request.form.get("symbol"))

        if quote == None:
            return apology("Input proper stock symbol", 400)

        return render_template("quoted.html", name = quote['name'], symbol = quote['symbol'], price = quote['price'])

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():

    """Register user"""

    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        elif not request.form.get("password"):
            return apology("must provide password", 400)

        elif not request.form.get("confirmation"):
            return apology("must provide the same password", 400)

        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("passwords must match", 400)

        hashpw = generate_password_hash(request.form.get("password"), method='pbkdf2:sha256', salt_length=8)

        # Query database for username
        result = db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)",
                          username=request.form.get("username"), hash=hashpw)

        if not result:
            return apology("username already exists", 400)

        # Remember which user has logged in
        session["user_id"] = result

        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    from time import gmtime, strftime

    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("Must submit a stock")

        elif not request.form.get("shares"):
            return apology("must provide number of shares", 400)

        stocks = db.execute("SELECT Stock, SUM(`Number of Shares`) FROM transactions WHERE ID = :ID AND Stock = :stock GROUP BY Stock", ID = session["user_id"], stock = request.form.get("symbol"))
        sharesowned = stocks[0]['SUM(`Number of Shares`)']

        if int(request.form.get("shares")) > sharesowned:
            return apology("Can't sell more shares than you own", 400)

        time = strftime("%a, %d %b %Y %H:%M:%S +0000", gmtime())

        quote = lookup(request.form.get("symbol"))

        db.execute("INSERT INTO transactions VALUES(:ID, :Stock, :stockprice, :numofshares, :time)",
                ID = session["user_id"], Stock = request.form.get("symbol"), stockprice = quote['price'], numofshares = (int(request.form.get("shares")) * (-1)), time = time)

        db.execute("UPDATE users SET cash = cash + (:sharescost) WHERE id = :id", sharescost = int(request.form.get("shares")) * quote['price'], id = session["user_id"])

        return redirect("/")

    else:
        stocksymbols = db.execute("SELECT Stock FROM transactions WHERE ID = :ID GROUP BY Stock", ID = session["user_id"])

        return render_template("sell.html", stocks = stocksymbols)

@app.route("/add", methods=["GET", "POST"])
@login_required
def add():

    if request.method == "POST":

        #Check if anything was entered into field
        if not request.form.get("addcash"):
            return redirect("/add")
        else:
            if int(request.form.get("addcash")) <= 0:
                return apology("Cash can't be negative")
            else:
                db.execute("UPDATE users SET cash = cash + (:addcash) WHERE id = :id", addcash = int(request.form.get("addcash")), id = session["user_id"])
                return redirect("/")

    else:
        return render_template("add.html")

def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
