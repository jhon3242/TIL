a = [1,2,3,4,5]
b = 10,20,30,40,50
c = range(-5,5)
d = '안녕하세요'

print(b + b)
print(list(c) + list(c))
print(len(d))
print(len(d.encode('utf-8')))
print(b[1])
print(a.__getitem__(2))
print(a[2:-1])
print(a[0:5:2])
print(a[:3])
print(a[slice(1,3)])
