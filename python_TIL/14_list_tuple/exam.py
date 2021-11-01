a, b = map(int, input().split())
l = []
while a <= b:
	re = 1;
	for i in range(1, a + 1):
		re *= 2
	l.append(re)
	a += 1
l.pop(1)
l.pop(-2)
print(l)
