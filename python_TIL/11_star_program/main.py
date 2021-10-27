"""
for i in range(5):
	for j in range(5):
		print("*", end='')
	print()


for i in range(5):
	for j in range(i + 1):
		print('*', end='')
	print()
"""

for i in range(5):
	for j in range(i + 1):
		if j == i:
			print("*")
		else:
			print(' ', end='')
