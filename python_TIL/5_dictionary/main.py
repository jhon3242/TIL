#lux = {'health': 490, 'mana': 334, 'melee': 550, 'armor': 18.72}
lux = {'health' : 490, 'health' : 800, 'mana' : 334, 'melee' : 550, 'armor' : 18.82}
#print(lux)
#print(lux['health'])
#x = {100 : 'max', 10.23 : [4,3,4], False : 0}
#print(x)
pike = dict(health = 600, mana = 200, melee = 170, armor = 25.4)
zed = dict(zip(['health', 'mana', 'melee', 'armor'], [400, 200, 160, 24]))
rel = dict([('health', 400), ('mana', 340), ('melee', 200), ('armor', 60)])
joy = dict({'health' : 500, 'mana' : 380 , 'melee' : 346, 'armor' : 33.3})
print('health' in lux)
print('attack speed' not in lux)
print(len(pike))
