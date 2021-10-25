"""

i = 0
while i < 100:
	print('hello')
	i += 1


i = 100
while i > 0:
	print('hello')
	i -= 1


nb = int(input())
i = 0
while i < nb:
	print('hello')
	i += 1


import random

print(random.randint(1, 6))
print(random.randint(1, 6))
print(random.randint(1, 6))


import random

i = 0
while i != 3:
	i = random.randint(1, 6)
	print(i)


import random

dice = [1, 2, 3, 4, 5, 6]
print(random.choice(dice))
print(random.choice(dice))
print(random.choice(dice))




"""

while True:
	print('hello')

