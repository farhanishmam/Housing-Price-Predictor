# -*- coding: utf-8 -*-
"""
Created on Tue Oct  8 00:45:43 2019

@author: NAFIS
"""

import random

f = open("data.txt", "w")

i = 0
total = 100

while i < total:
    x = random.uniform(800, 2000)
    y = random.uniform(4000*x - 100000, 4000*x + 100000)
    f.write(str(x) + " " + str(y))
    i = i + 1
    if i < total:
        f.write("\n")
    
f.close()