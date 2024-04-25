import aiframework as ai

# if we give as input (0, 0) it says: returned a result with an exception set (SystemError: <built-in function Point>)

i = ai.Point(0, 0)
i.x = 2
i.y = 3
print(i.x, i.y)
print('hola')
