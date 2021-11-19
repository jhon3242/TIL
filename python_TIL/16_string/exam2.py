x = list(map(int,input().split(';')))
x.sort(reverse=True)
for i in x:
	print("{0:>9,}".format(i))
