"""
test = [1,2,3]
print(dir(test))


it = [1,2,3].__iter__()
print(it.__next__())
print(it.__next__())
print(it.__next__())


it = range(3).__iter__()
print(it.__next__())
print(it.__next__())
print(it.__next__())




class Counter:
	def __init__(self, stop):
		self.current = 0
		self.stop = stop

	def __iter__(self):
		return self

	def __next__(self):
		if self.current < self.stop:
			r = self.current
			self.current += 1
			return r
		else:
			raise StopIteration

for i in Counter(3):
	print(i, end= ' ')



class Counter:
	def __init__(self, stop):
		self.stop = stop

	def __getitem__(self, index):
		if index < self.stop:
			return index
		else:
			raise IndexError

print(Counter(3)[0], Counter(3)[1], Counter(3)[2])




it = iter(range(3))
print(next(it))
print(next(it))
print(next(it))



import random

it = iter(lambda : random.randint(0, 5), 2)
print(next(it))
print(next(it))
print(next(it))
print(next(it))
print(next(it))
print(next(it))
"""

class C:
	def __init__(self, start, stop):
		self.stop = stop
		self.start = start
		pass

	def __getitem__(self, index):
		#index = self.start
		if self.start < self.stop:
			return index
		else:
			raise IndexError

a = C(2,5)
print(a)
print(a[0])
print(a[1])
