"""
word = input('단어를 입력하세요: ')

ret = True
for i in range(len(word) // 2):
	if word[i] != word [-1 -i]:
		ret = False
		break
print(ret)


word = input('단어를 입력하세요: ')
print(word == word[::-1])


word = 'level'
print(list(reversed(word)))


text = 'Hello'
for i in range(len(text) - 1):
	print(text[i], text[i + 1], sep='')


text = 'Hello'
for i in zip(text, text[1:]):
	print(i[0], i[1], sep='')


text = 'Hello'
print([text[i:] for i in range(3)])
"""

text = 'Hello'
sliced = [text[i:] for i in range(3)]
print(list(zip(*sliced)))

