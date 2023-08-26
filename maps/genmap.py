#!/usr/bin/python3
#/usr/bin/python3
from random import random
from sys import argv

if len(argv) != 4:
    exit(0)
size_y = 0
size_x = 0
density = 0
try:
    size_y = int(argv[1])
    size_x = int(argv[2])
    density = int(argv[3])
except:
    exit(0)

obj = []
chars = ".ox"
print(argv[1] + chars)
for y in range(size_y):
    obj.append([])
    for x in range(size_x):
        r = round(random() * (size_y*size_x))
        if (r < density):
            obj[y].append(chars[1])
        else:
            obj[y].append(chars[0])

for y in range(size_y):
    for x in range(size_x):
        print(obj[y][x], end="")
    print("\n", end="")
