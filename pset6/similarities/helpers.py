#import function to create a list of sentences in a string"""
from nltk.tokenize import sent_tokenize

#define function that creates list of all substrings of length n in a string
def listofsubstrings(s, n):

    #initialize empty list and counter
    substrings = []
    i = 0

    #check if the substring length is longer than the string. If yes, return an empty list since there will be no matches
    if len(s) < n:
        return substrings

    #create all substrings of length n of a string and append them to a list
    #stops appending once there are no substrings of length n remaining
    for x in s:
        substrings.append(s[i: i + n])
        i += 1
        if len(s) - i < n:
            break

    return substrings

def lines(a, b):
    """Return lines in both a and b"""

    #create lists of lines
    list1 = a.splitlines()
    list2 = b.splitlines()

    #initialize an empty list
    list3 = []

    #compare both previous lists and appends the ones that are in both lists to a new list
    for n in list1:
        for m in list2:
            if n == m:
                list3.append(n)
            else:
                pass

    #remove duplicates in list of matches
    for k in list3:
        while list3.count(k) > 1:
            list3.remove(k)

    return list3

def sentences(a, b):
    """Return sentences in both a and b"""

    list1 = sent_tokenize(a)
    list2 = sent_tokenize(b)

    list3 = []

    for n in list1:
        for m in list2:
            if n == m:
                list3.append(n)
            else:
                pass

    for k in list3:
        while list3.count(k) > 1:
            list3.remove(k)

    return list3


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    list1 = listofsubstrings(a, n)
    list2 = listofsubstrings(b, n)

    list3 = []

    for n in list1:
        for m in list2:
            if n == m:
                list3.append(n)
            else:
                pass

    for k in list3:
        while list3.count(k) > 1:
            list3.remove(k)

    return list3