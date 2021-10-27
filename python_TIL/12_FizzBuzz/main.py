"""
for i in range(1, 101):
	if i % 3 == 0:
		print("Fizz", end='')
	if i % 5 == 0:
		print("Buzz", end='')
	if i % 3 != 0 and i % 5 != 0:
		print(i, end='')
	print()
"""

for i in range(1, 101):
	print('Fizz' * (i % 3 == 0) + 'Buzz' * (i % 5 == 0) or i)
