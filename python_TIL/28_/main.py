"""
x = 10
def foo():
	# global x
	x = 20
	print(x)

foo()
print(x)



x = 10
print(locals())



def A():
	x = 10
	def B():
		x = 20
	B()
	print(x)

A()



def A():
	x = 10
	def B():
		nonlocal x
		x = 20
	B()
	print(x)

A()



def A():
    x = 10
    y = 100
    def B():
        x = 20
        def C():
            nonlocal x
            nonlocal y
            x = x + 30
            y = y + 300
            print(x)
            print(y)
        C()
    B()

A()



def calc():
	a = 3
	b = 5
	def mul_add(x):
		return a * x + b
	return mul_add

c = calc()
print(c(10))
"""

def calc():
	a = 3
	b = 5
	return lambda x : a * x + b

c = calc()
print(c(10))
