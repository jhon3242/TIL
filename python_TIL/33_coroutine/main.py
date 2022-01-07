"""
def number_coroutine():
	while (True):
		x = (yield)
		print(x)

co = number_coroutine()
next(co)

co.send(1)
co.send(2)
co.send(3)




def sum_coroutine():
	total = 0
	while (True):
		x = (yield total)
		total += x

co = sum_coroutine()
next(co)
print(co.send(1))
print(co.send(2))
print(co.send(3))



def number_coroutine():
    while True:
        x = (yield)
        print(x, end=' ')

co = number_coroutine()
next(co)

for i in range(20):
	co.send(i)

co.close()



def number_coroutine():
	try:
		while True:
			x = (yield)
			print(x, end=' ')
	except GeneratorExit:
		print()
		print("코루틴 종료")

co = number_coroutine()
next(co)

for i in range(20):
	co.send(i)

co.close()
"""

def accumulate():
	total = 0
	while True:
		x = (yield)
		if x is None:
			return total
		total += x

def sum_coroutine():
	while True:
		total = yield from accumulate()
		print(total)

co = sum_coroutine()
next(co)


for i in range(1, 11):    # 1부터 10까지 반복
    co.send(i)            # 코루틴 accumulate에 숫자를 보냄
co.send(None)             # 코루틴 accumulate에 None을 보내서 숫자 누적을 끝냄

for i in range(1, 101):   # 1부터 100까지 반복
    co.send(i)            # 코루틴 accumulate에 숫자를 보냄
co.send(None)             # 코루틴 accumulate에 None을 보내서 숫자 누적을 끝냄
