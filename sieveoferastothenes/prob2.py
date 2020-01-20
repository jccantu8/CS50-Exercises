fibb = [1,2]
i = 2;
k = 0;
j = 0;
h = 0;

for i in range(2,4000000):
  k = fibb[i-2] + fibb[i-1] ;
  fibb.append(k);

for j in fibb:
  if (j % 2 == 0):
    h += 0;
  else:
    pass;

print(h);