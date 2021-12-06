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
"""
