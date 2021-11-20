"""
x = {'a' : 10, 'b' : 20, 'c' : 30, 'd' : 40}
x.setdefault('e')
print(x)


x = {'a' : 10, 'b' : 20, 'c' : 30, 'd' : 40}
x.update(a = 90)
print(x)
x.update(e = 50)
print(x)
x.update({'a' : 100, 'f' : 60})
print(x)


x = {'a' : 10, 'b' : 20, 'c' : 30, 'd' : 40}
x.pop('a')
del x['b']
print(x)



x.popitem()
print()

x = {'a' : 10, 'b' : 20, 'c' : 30, 'd' : 40}
print(x.get('b'))


x = {'a' : 10, 'b' : 20, 'c' : 30, 'd' : 40}
print(x.items())
print(x.keys())
print(x.values())


keys = ['a', 'b', 'c', 'd']
x = dict.fromkeys(keys)
print(x)


x = {'a' : 10, 'b' : 20, 'c' : 30, 'd' : 40}
print(x.keys())

keys = ['a', 'b', 'c', 'd']
x = {key : value for key, value in dict.fromkeys(keys).items()}
print(x)


x = {'a': 10, 'b': 20, 'c': 30, 'd': 40}
for key, value in x.items():
	if value == 20:
		del x[value]
print(x)
"""
x = {'a': 10, 'b': 20, 'c': 30, 'd': 40}
x = {key : value for key, value in x.items() if value != 20}
print(x)
