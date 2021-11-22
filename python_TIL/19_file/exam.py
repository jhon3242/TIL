with open('words.txt', 'r') as file:
	words = file.readline()
	line = words.split()
	for word in line:
		if 'c' in word:
			print(word.strip(',.'))

