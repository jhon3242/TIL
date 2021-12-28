"""
from math import sqrt
class Point2D:
	def __init__(self, x, y):
		self.x = x
		self.y = y

p1 = Point2D(x = 30, y = 20)
p2 = Point2D(x = 60, y = 50)

a = p2.x - p1.x
b = p2.y - p1.y

c = sqrt(a*a + b*b)
print(c)
 """

from math import sqrt
import collections

Point2D = collections.namedtuple('Point2D', ['x', 'y'])
p1 = Point2D(x=30, y=20)
p2 = Point2D(x=60, y=50)

a = p1.x - p2.x
b = p1.y - p2.y
c = sqrt(a**2 + b**2)
print(c)
