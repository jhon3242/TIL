"""
i = 0
while True:
	print(i)
	i += 1
	if i == 100:
		break


for i in range(1000):
	print (i)
	i += 1
	if i == 100:
		break


for i in range(100):
	if i % 2 == 0:
		continue
	print(i)


"""
nb = int(input('반복할 횟수 :'))

for i in range(nb + 1):
	if i % 2 == 0:
		continue
	print(i)
