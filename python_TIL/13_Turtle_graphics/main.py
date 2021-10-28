"""

import turtle as t

t.shape('turtle')
t.color('#FF69B4')    # 핫핑크(hotpink)
t.begin_fill()
n = int(input())
for i in range(n):
	t.forward(100)
	t.right(360/n)
t.end_fill()
t.mainloop()


import turtle as t

t.shape('turtle')
t.circle(120)
t.mainloop()
"""


import turtle as t

t.shape('circle')
t.speed('fastest')
for i in range(500):
	t.forward(i)
	t.right(91)
t.mainloop()
