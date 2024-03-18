import aiframework as ai

# if we give as input (0, 0) it says: returned a result with an exception set (SystemError: <built-in function Point>)

i = ai.Point(1, 1)
print(i)
print(i.x, i.y)
i.x = 1
print(i.x, i.y)
