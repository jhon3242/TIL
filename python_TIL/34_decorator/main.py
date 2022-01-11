"""
def trace(fun):
	def wrapper():
		print(fun.__name__, '함수 시작')
		fun()
		print(fun.__name__, '함수 끝')
	return wrapper()


def hello():
    print('hello')

def world():
    print('world')

trace(hello)
trace(world)



def abc(fun):
	def wrapper():
		print(fun.__name__, '함수 시작')
		fun()
		print(fun.__name__, '함수 끝')
	return wrapper

@abc
def hello():
    print('hello')

@abc
def world():
    print('world')

hello()
world()



def trace(func):
	def wrapper(*args):
		for i in args:
			print(i, end=' ')
		print()
		print(func(*args))
	return wrapper


@trace
def get_max(*args):
	return max(args)


get_max(1,6,4,2,8,2)




def trace(func):
	def wrapper(self, a, b):
		r = func(self, a, b)
		print(r)
	return wrapper


class c:
	@trace
	def add(self, a, b):
		return a + b


tmp = c()
tmp.add(6, 4)





def is_multiple(x):
	def deco(func):
		def wrapper(a, b):
			c = func(a, b)
			print(f"{c}는 {x}의 배수가",end=' ')
			if c % x == 0:
				print("맞다.")
			else:
				print("아니다.")
		return wrapper
	return deco

@is_multiple(5)
def add(a, b):
	return a + b

add(3, 7)




class Trace:
	def __init__(self, func):
		self.func = func

	def __call__(self):
		print('함수의 시작')
		self.func()
		print('함수의 끝')

@Trace
def hello():
	print('hello')

hello()




class Trace:
	def __init__(self, func):
		self.func = func

	def __call__(self, *args, **kwargs):
		r = self.func(*args, **kwargs)
		print(f"매개변수 :{args}")
		print(f"리턴값 :{r}")

@Trace
def add(a, b):
	return a + b

add(4, 5)
"""



class IsMultiple:
	def __init__(self, x):
		self.x = x

	def __call__(self, func):
		def wrapper(a, b):
			r = func(a, b)
			print(f"{func.__name__} 함수의 반환값은 {self.x}의 배수가", end = ' ')
			if r % self.x == 0:
				print("맞다.")
			else:
				print("아니다.")
		return wrapper

@IsMultiple(3)    # 데코레이터(인수)
def add(a, b):
	return a + b

add(10, 21)
