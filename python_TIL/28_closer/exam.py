def countdown(n):
	i = n + 1
	def down():
		nonlocal i
		i -= 1
		return i
	return down


n = int(input())

c = countdown(n)
for i in range(n):
    print(c(), end=' ')
