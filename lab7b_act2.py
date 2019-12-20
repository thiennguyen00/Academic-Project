#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct  9 12:45:11 2019

@author: nguyenthien
"""

import math

#dimension_1 = int(input('Please enter the dimension of first vector: '))
#dimension_2 = int(input('Please enter the dimension of second vector: '))

print('\n**Please note that the two vectors have to have the same dimension.**\n')

A = str(input('Please enter first array of number (separate by white space): '))
B = input('Please enter second array of number (separate by white space): ')

vector_A = A.split()
vector_B = B.split()
vector_C = vector_A
vector_D = vector_B

sum_A = 0
sum_B = 0

#magnitude of vector A:
for i in range(len(vector_A)):
    sum_A += int(vector_A[i]) **2
    
magnitude_A = math.sqrt(sum_A)
print('\nMagnitude of vector A: ', magnitude_A)


#magnitude of vector B:
for i in range(len(vector_B)):
    sum_B += int(vector_B[i]) **2
    
magnitude_B = math.sqrt(sum_B)
print('\nMagnitude of vector B: ', magnitude_B)


#converting inputs fromt string to integers: 
for i in range(len(vector_A)):
    vector_C[i] = int(vector_A[i])

for i in range(len(vector_B)):
    vector_D[i] = int(vector_B[i])
    
#Find A+B and A-B: 
sum1 = vector_C[:]

for i in range(len(vector_C)):
    sum1[i] = vector_C[i] + vector_D[i]

subtract = vector_C[:]
    
for i in range(len(vector_C)):
    subtract[i] = vector_C[i] - vector_D[i]

print('\nA+B = ', sum1)
print('\nA-B = ', subtract)

#Find dot product
dot_product = vector_C[:]

for i in range(len(vector_C)):
    dot_product[i] = vector_C[i]*vector_D[i]
    
print('\nThe dot produc of two vectors are: ', dot_product)

    