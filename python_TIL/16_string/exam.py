book = input().split()
cnt = 0
for x in book:
	x = x.strip(",. ")
	if (x == "the"):
		cnt += 1
print(cnt)
