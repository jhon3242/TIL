"""
a = 'Hello World!'
print(a.replace('World', 'Python'))
print(a)


table = str.maketrans('abcde', '12345')
print('ace'.translate(table))


l = 'apple, pear, grape, pineapple, orange'.split(', ')
print(l)
l = ' '.join(l)
print(l)


l =  '   Python   '
print(l.lstrip())
print(l.rstrip())
print(l.strip())


a = 'python'
print(a.ljust(10))
print(a.rjust(10))


print('python'.rjust(10).upper())


print('123'.zfill(5))


name = "james"
print('I am %s' % name)

nb = 21
print("%03d" % nb)
print("{0:03d}".format(2, 4))


print("{0:>10,}".format(121233))
"""
path = 'C:\\Users\\dojang\\AppData\\Local\\Programs\\Python\\Python36-32\\python.exe'
print(path[path.rfind('\\') + 1])
