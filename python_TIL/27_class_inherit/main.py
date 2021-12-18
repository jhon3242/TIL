"""
class Person:
	def greeting(self):
		print('안녕하세요')

class Student(Person):
	def study(self):
		print('공부하기')

james = Student()
james.greeting()
james.study()



class Person:
	def greeting(self):
		print("hello")

class Personlist:
	def __init__(self):
		self.personlist = []

	def append_person(self, person):
		self.personlist.append(person)



class Person:
	def __init__(self):
		print("Person__init")
		self.hello = '안녕하세요'

class Student(Person):
	def __init__(self):
		print("Student__init")
		self.school = "접니다."

james = Student()
print(james.school)
print(james.hello)



class Person:
	def __init__(self):
		print("Person__init")
		self.hello = '안녕하세요'

class Student(Person):
	def __init__(self):
		print("Student__init")
		super().__init__()
		self.school = "접니다."

james = Student()
print(james.school)
print(james.hello)


class Person:
	def __init__(self):
		print("Person__init")
		self.hello = '안녕하세요'

class Student(Person):
	pass

james = Student()
print(james.hello)


class Person:
	def greeting(self):
		print('안녕하세요')

class Student(Person):
	def greeting(self):
		print('안녕하세요 저는 학생입니다.')

james = Student()
james.greeting()



class Person:
	def greeting(self):
		print('안녕하세요')

class Student(Person):
	def greeting(self):
		super().greeting()
		print('저는 학생입니다.')

james = Student()
james.greeting()



class Person:
	def greeting(self):
		print("안녕하세요")

class University:
	def manage_credit(self):
		print("학점 관리")

class Undergraduate(Person, University):
	def study(self):
		print("공부하기")

james = Undergraduate()
james.greeting()
james.manage_credit()
james.study()




class A:
	def greeting(self):
		print("I'm A")

class B(A):
	def greeting(self):
		print("I'm B")

class C(A):
	def greeting(self):
		print("I'm C")

class D(B, C):
	pass

x = D()
x.greeting()
"""

from abc import *

class StudentBase(matclass=ABCMeta):
	@abstractmethod
	def study(self):
		pass

	@abstractmethod
	def go_to_school(self):
		pass

class Student(StudentBase):
	def study(self):
		print("공부하기")

james = Student()
james.study()
