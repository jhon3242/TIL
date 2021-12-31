class TimeIterator:
	def __init__(self, start, stop):
		self.start = start
		self.stop = stop
	def __getitem__(self, index):
		if self.start + index < self.stop :
			return TimeIterator.to_str_time(*TimeIterator.to_time(self.start + index))
		else:
			raise StopIteration


	@staticmethod
	def to_str_time(h,m,s):
		if h >= 10:
			h = str(h)
		else:
			h = '0' + str(h)
		if m >= 10:
			m = str(m)
		else:
			m = '0' + str(m)
		if s >= 10:
			s = str(s)
		else:
			s = '0' + str(s)
		return h + ':' + m + ':' + s

	@staticmethod
	def to_time(time):
		h = 0
		m = 0
		s = time
		while s >= 60:
			s -= 60
			m += 1
			if m >= 60:
				m -= 60
				h += 1
				if h >= 24:
					h = 0
		return h,m,s

start, stop, index = map(int, input().split())
#print(TimeIterator(start, stop)[2])

for i in TimeIterator(start, stop):
    print(i)

print('\n', TimeIterator(start, stop)[index], sep='')

