col, row = map(int, input().split())

matrix = []
for x in range(row):
	matrix.append(list(input()))
#print(matrix)

re = []
for y in range(row):
	line = []
	for x in range(col):
		line.append(0)
	re.append(line)
#print(re)

for y in range(row):
	for x in range(col):
		if matrix[y][x] == '*':
			if y - 1 >= 0 and x - 1 >= 0:
				re[y - 1][x - 1] += 1
			if y - 1 >= 0 and x + 1 < col:
				re[y - 1][x + 1] += 1
			if y + 1 < row and x -1 >= 0:
				re[y + 1][x - 1] += 1
			if y + 1 < row and x + 1 < col:
				re[y + 1][x + 1] += 1
			if x - 1 >= 0:
				re[y][x - 1] += 1
			if x + 1 < col:
				re[y][x + 1] += 1
			if y - 1 >= 0:
				re[y - 1][x] += 1
			if y + 1 < row:
				re[y + 1][x] += 1
for y in range(row):
	for x in range(col):
		if matrix[y][x] == '*':
			re[y][x] = '*'
		print(re[y][x], end='')
	print()

