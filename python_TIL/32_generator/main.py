"""
def number_gen():
	yield 0
	yield 1
	yield 2

for i in number_gen():
	print(i)



def number_gen():
	yield 0
	yield 1
	yield 2

print(dir(number_gen()))


class c:
	def __init__(self):
		pass

	def


def number_gen():
	yield 0
	yield 1
	yield 2

g = number_gen()

a = next(g)
print(a)
b = next(g)
print(b)
c = next(g)
print(c)




def number_gen():
	yield 0
	yield 1
	return 'this is error'

try:
	g = number_gen()
	next(g)
	next(g)
	next(g)
except Exception as e:
	print(e)




def number_gen(stop):
	n = 0
	while (n < stop):
		yield n
		n += 1

for i in number_gen(3):
	print(i)




def upper_gen(n):
	for i in n:
		yield i.upper()

fruits = ['apple', 'pear', 'grape', 'pineapple', 'orange']

for i in upper_gen(fruits):
	print(i)




def number_gen():
	numbers = [1, 2, 3]
	yield from numbers

for i in number_gen():
	print(i)
"""



def nubmer_gen(stop):
	n = 0
	while (n < stop):
		yield n
		n += 1


def three_gen():
	yield from nubmer_gen(3)

for i in three_gen():
	print(i)
