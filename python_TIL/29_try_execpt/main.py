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
"""



