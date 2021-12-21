"""
plus_ten = lambda x : x + 10
print(plus_ten(3))

print((lambda x : x + 10)(20))



def plus_ten(x):
	return x + 10

print(list(map(plus_ten, [1,2,3])))


x = list(map(lambda x : x + 10, [1,2,3]))
print(x)


x = list(map(lambda x : str(x) if x % 3 == 0 else x, [1,2,3,4,5,6,7,8,9]))
print(x)


print(list(map(lambda x : str(x) if x == 1 else float(x) if x == 2 else x + 10, [1,2,3,4,5,6,7,8,9])))



a = [1, 2, 3, 4, 5]
b = [2, 4, 6, 8, 10]
print(list(map(lambda x, y : x * y , a, b)))


def f(x):
	return x > 5 and x < 10

a = [8, 3, 2, 10, 15, 7, 1, 9, 0, 11]
print(list(filter(f, a)))



a = [8, 3, 2, 10, 15, 7, 1, 9, 0, 11]
print(list(filter(lambda x : x >= 0, a)))



from functools import reduce
a = [1,2,3,4,5]
def f(x ,y):
	return x + y

print(reduce(f, a))

"""
from functools import reduce
a = [1,2,3,4,5]
print(reduce(lambda x, y : x + y, a))
