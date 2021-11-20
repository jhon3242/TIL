"""
fruits = {'strawberry', 'grape', 'orange', 'pineapple', 'cherry'}
print(fruits)


fruits = {'orange', 'orange', 'cherry'}
print(fruits)

fruits = {'strawberry', 'grape', 'orange', 'pineapple', 'cherry'}
print('grape' in fruits)


a = "apple"
print(set(a))


a = frozenset(range(10))
print(a)


a = {1, 2, 3, 4}
b = {3, 4, 5, 6}
print(a | b)
print(a & b)
print(a - b)
print(a ^ b)


a = {1, 2, 3, 4}
a |= {5}
print(a)

a = {1, 2, 3, 4}
a &= {0, 1, 2, 3, 4}
print(a)



a = {1, 2, 3, 4}
print(a <= {1, 2, 3, 4})
"""

a = {i for i in range(10) if i != 2 and i != 7}
print(a)
