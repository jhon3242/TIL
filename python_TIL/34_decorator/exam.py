class html_tag:
	def __init__(self, tag):
		self.tag = tag

	def __call__(self, func):
		def wrapper():
			return '<{0}>{1}</{0}>'.format(self.tag, func())
		return wrapper


a, b = input().split()

@html_tag(a)
@html_tag(b)
def hello():
    return 'Hello, world!'

print(hello())
