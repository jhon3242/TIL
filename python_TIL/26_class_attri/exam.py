class Time:
	def __init__(self, hour, minute, second):
		self.hour = hour
		self.minute = minute
		self.second = second

	@staticmethod
	def is_time_valid(string):
		h, m, s = map(int, string.split(':'))
		if h <= 24 and m <= 59 and s <= 60:
			return True
		else:
			return False
	@classmethod
	def from_string(cls, string):
		h, m, s = map(int, string.split(':'))
		x = cls(h, m, s)
		return x




time_string = input()

if Time.is_time_valid(time_string):
	t = Time.from_string(time_string)
	print(t.hour, t.minute, t.second)
else:
	print('잘못된 시간 형식입니다.')
