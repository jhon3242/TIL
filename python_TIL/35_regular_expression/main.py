import re

# print(re.match('hello', 'hello world'))
# print(re.match('hi', 'hello world'))


# print(re.search('^hello ', 'hello world'))
# print(re.search('d$', 'hello world'))


# print(re.match('hello|word', 'hello'))


# print(re.match('[0-9]*', ''))


# print(re.match('a*@', '@'))
# print(re.match('a+@', '@'))
# print(re.match('a+@', 'a@'))


# print(re.match('abc[0-9]?d', 'abcd'))
# print(re.match('ab.d', 'abcd'))


# print(re.match('h{3}', 'hellohiho'))
# print(re.match('h{3}', 'hhhello'))
# print(re.match('(hello){3}', 'hellohellohellohi'))



# print(re.match('[0-9]{3}-[0-9]{4}-[0-9]{4}', '010-0000-0000'))
# print(re.match('[0-9]{2,3}-[0-9]{3,4}-[0-9]{4}', '02-000-0000'))



# print(re.match('[a-zA-Z0-9]+', 'hello'))
# print(re.match('[A-Z0-9]+', 'hello'))


# print(re.match('[^A-Z]+', 'aLLo'))


# print(re.match('\*+', '1 ** 1'))
# print(re.match('[$)(a-z]', '$(document)'))



# print(re.match('\D+', 'a123'))



# p = re.compile('[0-9]+')
# print(p.match('1234'))
# print(p.search('hell3o'))


# m = re.match('([0-9]+) ([0-9]+)', '123 4356')
# print(m.group(0))
# print(m.group(1))
# print(m.group(2))



# m = re.match('(?P<func>[a-zA-Z]\w+)\((?P<args>\w+)\)', 'print(1234)')
# print(m.group('func'))



# m = re.findall('[0-9]+', '0 2 fizz 4 buzz fizz 7 8')
# print(m)


# print(re.match('(.[a-z]+)*$', ''))
# print(re.match('(.[a-z]+)*$', '#z'))
# print(re.match('(.[a-z]+)*$', '@A'))




# m = re.sub('apple|orange','fruit', 'apple in the orange box')
# print(m)
# m = re.sub('[0-9]+', 'n', '1 2 Fizz 4 Buzz Fizz 7 8')
# print(m)



# def multiple10(m):
# 	n = int(m.group())
# 	return str(n * 10)

# print(re.sub('[0-9]+', multiple10, '1 2 Fizz 4 Buzz Fizz 7 8'))


# print(re.sub('[0-9]+', lambda x : str(int(x.group()) * 10), '1 2 Fizz 4 Buzz Fizz 7 8'))



# print(re.sub('([a-z]+) ([0-9]+)', '\\2 \\1 \\2 \\1', 'hello 1234'))



# 다음은 '{ "name": "james" }'을 '<name>james</name>' 형식으로 바꾼다
print(re.sub('{ *"(\w+)": *"(\w+)" *}', '<\\1>\\2</\\1>', '{ "name": "james" }'))
print(re.sub('{ *"(?P<first>\w+)": *"(?P<second>\w+)" *}', '<\\g<first>>\\g<second></\\g<first>>', '{ "name": "james" }'))
