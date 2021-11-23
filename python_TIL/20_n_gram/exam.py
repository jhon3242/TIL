with open('words.txt', 'r') as file:
	words = [i.strip('\n') for i in file]
	for word in words:
		if (word == word[::-1]):
			print(word)





