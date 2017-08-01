palin = lambda n: str(n) == str(n)[::-1]

import math

cnt = 0

a = 1
b = 10**14

k = len(str(b))

x = (3 *  (k//2) + 2* (k % 2))
y = 2*(2**(k/2-2) - 1)
z = (1 + (k-1)//2)*((k-1)//2)/2

print x,y,z
print x + y + z + 1


print math.log(b,11)

for x in range(a,int(math.sqrt(b+1))):
	if palin(x) and palin(x**2):
		print x, x% 11 == 0
		cnt += 1
		
print cnt
