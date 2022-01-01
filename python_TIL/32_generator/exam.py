import math
def is_prime(n):
	x = 2
	while (x <= math.sqrt(n)):
		if n % x == 0:
			return False
		x += 1
	return True


def prime_number_generator(start, stop):
	gen = (i for i in range(start, stop + 1) if is_prime(i))
	yield from gen


start, stop = map(int, input().split())

g = prime_number_generator(start, stop)
print(type(g))
for i in g:
    print(i, end=' ')
