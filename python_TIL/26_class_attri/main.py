"""
class Person:
	bag = []

	def put_bag(self, stuff):
		self.bag.append(stuff)

james = Person()
james.put_bag('book')

maria = Person()
maria.put_bag('key')

print(james.bag)
print(maria.bag)


class Person:
	def __init__(self):
		self.bag = []

	def put_bag(self, stuff):
		self.bag.append(stuff)

james = Person()
james.put_bag('열쇠')
maria = Person()
maria.put_bag('키')

print(james.bag)
print(maria.bag)


class Knight:
	__item_limit = 10

	def	print_item_limit(self):
		print(Knight.__item_limit)

x = Knight()
x.print_item_limit()


class Person:
    '''사람 클래스입니다.'''

    def greeting(self):
        '''인사 메서드입니다.'''
        print('Hello')

print(Person.__doc__)
print(Person.greeting.__doc__)

x = Person()
print(x.greeting.__doc__)


class Calc:
	@staticmethod
	def add(a, b):
		print(a + b)

	@staticmethod
	def mul(a, b):
		print(a * b)

Calc.add(10, 20)
Calc.mul(10, 20)
"""

class Person:
	count = 0

	def __init__(self):
		Person.count += 1

	@classmethod
	def print_count(cls):
		print(f"{cls.count} 명이 생성되었습니다.")

james = Person()
maria = Person()

Person.print_count()
