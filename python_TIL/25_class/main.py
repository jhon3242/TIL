"""
class Person:
	def greeting(self):
		print("Hello")
james = Person()
james.greeting()

b = list(range(10))
b.append(20)
print(b)

def factorial(n):
    if not isinstance(n, int) or n < 0:    # n이 정수가 아니거나 음수이면 함수를 끝냄
        return None
    if n == 1:
        return 1
    return n * factorial(n - 1)


class Person:
	def __init__(self):
		self.hello ='안녕하세요'
	def greeting(self):
		print(self.hello)

james = Person()
james.greeting()

class Person:
	def __init__(self, name, age, address):
		self.hello ='안녕하세요'
		self.name = name
		self.age = age
		self.address = address

	def greeting(self):
		print("{} 저는 {}입니다.".format(self.hello, self.name))

james = Person("제임스", 20, "경기도 수원시")
james.greeting()

print("이름 :", james.name)
print("나이 :", james.age)
print("주소 :", james.address)



class Person:
	def __init__(self, *args):
		self.name = args[0]
		self.age = args[1]
		self.address = args[2]

james = Person(*["제임스", 20, "경기도 수원시"])


class Person():
	def __init__(self, **kwargs):
		self.name = kwargs['name']
		self.age = kwargs['age']
		self.address = kwargs['address']

james1 = Person(name = "제임스", age = 20, address = "경기도 수원시")
james2 = Person(**{'name' : '제임스', 'age' : 20, 'address' : '경기도 수원시'})

print(james1.name)


class Person:
	pass

james = Person()
james.name = "제임스"
print(james.name)


class Person:
	__slots__ = ['name', 'age', 'address']

james = Person()
james.name = '제임스'
james.gender = '남자'
"""

class Person:
	def __init__(self, name, age, address, wallet):
		self.name = name
		self.age = age
		self.address = address
		self.__wallet = wallet

	def pay(self, amount):
		if self.__wallet < amount:
			print('돈이 모자르네..')
			return
		self.__wallet -= amount


james = Person('제임스', 20, '경기도 수원시', 1000)
james.pay(700)
