"""
try :
	x = int(input('나눌 숫자를 입력하시오:'))
	print(10 / x)
except:
	print("예외가 발생했습니다.")



l = [10, 20, 30]
try:
	index, x = map(int, input('인덱스와 나눌 값을 지정해주세요').split())
	print(l[index] / x)
except ZeroDivisionError:
	print('숫자는 0 으로 나눌 수 없습니다.')
except IndexError:
	print('잘못된 인덱스 입니다.')




l = [10, 20, 30]
try:
	index, x = map(int, input('인덱스와 나눌 값을 지정해주세요').split())
	print(l[index] / x)
except ZeroDivisionError as e:
	print('숫자는 0 으로 나눌 수 없습니다.', e)
except IndexError as e:
	print('잘못된 인덱스 입니다.', e)


try:
	x = int(input())
	y = x / 10
except ZeroDivisionError as e:
	print(e)
else:
	print(y)



def fn():
	a = int(input())
	try:
		if a % 3 != 0:
			raise Exception('3의 배수가 아니다.')
		print(a)
	except Exception as a:
		print(a)
		raise RuntimeError('런타임 에러')

try:
	fn()
except:
	print('예외 발생')






x = int(input())
assert x % 3 == 0, '3의 배수가 아니다.'
print(x)
"""

class NotThreeMultipleError(Exception):
	def __init__(self):
		super().__init__('3의 배수가 아닙니다.')

def fn():
	try:
		x = int(input())
		if x % 3 != 0:
			raise NotThreeMultipleError
		print(x)
	except Exception as e:
		print('예외 발생', e)

fn()
