import re

url = input()
com = re.compile('^(https*://)([a-zA-Z0-9-]+)\.([a-zA-Z0-9-]+)(/+[a-zA-Z0-9-_\.?=])*')
if com.match(url):
	print(True)
else:
	print(False)
