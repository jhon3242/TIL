nb = int(input())

for i in range(1, nb + 1):
	for j in range(nb - i):
		print(' ', end='')
	max = i * 2 - 1
	for k in range(max):
		print('*', end='')
	print()
