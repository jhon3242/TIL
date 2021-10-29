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
"""

a = [10, 20, 30]
a[len(a):] = 40
print(a)
