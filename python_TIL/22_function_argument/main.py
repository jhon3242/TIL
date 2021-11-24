"""
print(10, 20, 30)


def print_number(a, b, c):
	print(a)
	print(b)
	print(c)
print_number(10, 20, 30)


def print_number(*args):
	for arg in args:
		print(arg)
print_number(10)
print_number(10, 20, 30, 40, 50)


def personal_info(name, age, address):
	print('이름: ', name)
	print('나이: ', age)
	print('주소: ', address)

x = {'name' : '홍길동', 'age' : 20, 'address' : '서울시 광진구'}
personal_info(**x)


x = {'name' : '홍길동', 'age' : 20, 'address' : '서울시 광진구'}
def personal_info(x):
	for key,value in x.items():
		print(key, value)
personal_info(x)


def personal_info(**kwargs):
    if 'name' in kwargs:    # in으로 딕셔너리 안에 특정 키가 있는지 확인
        print('이름: ', kwargs['name'])
    if 'age' in kwargs:
        print('나이: ', kwargs['age'])
    if 'address' in kwargs:
        print('주소: ', kwargs['address'])

def ft_personal_info(kwargs):
	for x, y in  kwargs.items():
		if 'name' in x:    # in으로 딕셔너리 안에 특정 키가 있는지 확인
			print('이름: ', kwargs['name'])
		if 'age' in x:
			print('나이: ', kwargs['age'])
		if 'address' in x:
			print('주소: ', kwargs['address'])

x = {'name' : '홍길동', 'age' : 20, 'address' : '서울시 광진구'}

personal_info(**x)
ft_personal_info(x)
"""
def personal_info(name, age, address='비공개'):
	print(name, age, address)
personal_info('choi', 22)

