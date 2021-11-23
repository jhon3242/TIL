"""
def hello():

	이 함수는 Hello, World! 문자열을 출력하는 함수이다.

	print('Hello, World!')


#hello()
#print(help(hello))
print(hello.__doc__)
"""

def add_sub(a, b):
	return a + b, a - b
x, y = add_sub(10, 20)
print(x)
print(y)
