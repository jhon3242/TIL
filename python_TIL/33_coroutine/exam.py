def calc():
	a = 0
	b = 0
	result = 0
	while True:
		x = (yield result)
		x = x.split()
		a = int(x[0])
		b = int(x[2])
		if x[1] == '+':
			result = a + b
		elif x[1] == '-':
			result = a - b
		elif x[1] == '*':
			result = a * b
		elif x[1] == '/':
			result = a / b



#expressions = input().split(', ')
expressions = ['3 * 4', '10 / 5', '20 + 39']


c = calc()
next(c)

for e in expressions:
    print(c.send(e))

c.close()
""""""


