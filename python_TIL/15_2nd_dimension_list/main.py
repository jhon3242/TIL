"""
a = [[10, 20], [30, 40], [50, 60]]
print(a)


a = []
a.append([10])
a.append([20])
a[0].append(11)
a[0].append(12)
a[1].append(22)
a.append([30])
a.append([40,41,42,43])
print(a)


from pprint import pprint
a = [[10, 20], [30, 40], [50, 60]]
pprint(a, width=20, indent= 4)



a = [[10, 20], [30, 40], [50, 60]]
for x,y in a:
	print(x, y)


a = [[10, 20], [30, 40], [50, 60]]
for i in a:
	for j in i:
		print(j, end= ' ')
	print()


a = []
for i in range(10):
	a.append(0)
print(a)


a = []
for i in range(3):
	l = []
	for j in range(2):
		l.append(0)
	a.append(l)
print(a)

a = [[0 for i in range(2)] for j in range(3)]
print(a)


a = [0] * 2
print(a)


a = [3, 1, 3, 2, 5]
re = []
for i in a:
	l = []
	for j in range(i):
		l.append(0)
	re.append(l)
print(re)


a = [[0] * i for i in [3, 1, 3, 2, 5]]
print(a)


students = [
    ['john', 'C', 19],
    ['maria', 'A', 25],
    ['andrew', 'B', 7]
]
print(sorted(students, key= lambda student: student[1]))
print(sorted(students, key=lambda student: student[2]))


a = [[1, 2], [10, 20]]
b = a
b[0][0] = 2
print(a)
print(b)


a = [[1, 2], [10, 20]]
b = a.copy()
b[0][0] = 2
print(a)
print(b)
"""
import copy
a = [[1, 2], [10, 20]]
b = copy.deepcopy(a)
b[0][0] = 2
print(a)
print(b)
