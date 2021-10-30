"""
a = [10, 20, 30]
a.append(40)
print(a)


a = []
a.append(10)
print(a)


a = [10, 20, 30]
a.append([500, 600])
print(a)
print(len(a))



a = [10, 20, 30]
a.extend([500, 600])
print(a)
print(len(a))


a = [10, 20, 30]
a.insert(1, 15)
print(a)


a = [10, 20, 30]
a.insert(len(a), 40)
print(a)


a = [10, 20, 30]
a[1:1] = [15, 16, 17]
print(a)


a = [10, 20, 30]
print(a.pop())
print(a)

a = [10, 20, 30]
a.remove(20)
print(a)


from collections import deque

a = deque([10, 20, 30])
print(a)
a.append(40)
print(a)
print(a.popleft())
print(a)



a = [10, 20, 30, 40, 50]
print(a.index(20))


a = [10, 20, 30, 40, 50]
print(a.count(20))



a = [10, 20, 30, 40, 50]
a.reverse()
print(a)


a = [10, 20, 30, 15, 20, 40]
a.sort(reverse=True)
print(a)


a = [10, 20, 30, 15, 20, 40]
print(sorted(a))
print(a)


a = [10, 20, 30]
a[len(a)] = 40
print(a)


a = [0, 0, 0, 0, 0]
b = a
b[2] = 99


a = [0, 0, 0, 0, 0]
b = a.copy()
print(a is b)
print(a == b)
b[2] = 99


a = [38, 21, 53, 62, 19]
for i in a:
	print(i)



for i in [38, 21, 53, 62, 19]:
	print(i)


a = [38, 21, 53, 62, 19]
for index, value in enumerate(a):
	print(index, value)


a = [38, 21, 53, 62, 19]
for index, value in enumerate(a, start=1):
	print(index, value)


a = [38, 21, 53, 62, 19]
for i in range(len(a)):
	print(a[i])


a = [38, 21, 53, 62, 19]
i = 0
while i <= len(a):
	print(a[i])
	i += 1


a = [38, 21, 53, 62, 19]
smallest = a[0]
for i in a:
	if i < smallest:
		smallest = i
print(i)


a = [38, 21, 53, 62, 19]
largest = a[0]
for i in a:
	if i > largest:
		largest = i
print(largest)


a = [38, 21, 53, 62, 19]
a.sort()
print(a[0])
a.sort(reverse=True)
print(a[0])


a = [38, 21, 53, 62, 19]
print(max(a))
print(min(a))


a = [10, 10, 10, 10, 10]
x = 0
for i in a:
	x += i
print(x)


a = [10, 10, 10, 10, 10]
print(sum(a))


a = [i for i in range(10)]
print(a)


a = [i * 2 for i in range(10)]
print(a)


a = [i for i in range(10) if i % 2 == 0]
print(a)


a = [i * j for i in range(2, 10) for j in range(1, 10)]
print(a)



a = [i * j for i in range(2, 10)
			for j in range(1, 10)]
print(a)


a = [1.2, 2.5, 3.7, 4.6]
for i in range(len(a)):
	a[i] = int(a[i])
print(a)


a = [1.2, 2.5, 3.7, 4.6]
a = list(map(int, a))
print(a)
"""
a = list(map(str, range(10)))
print(a)

