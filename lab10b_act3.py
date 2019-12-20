# By submitting this assignment, I agree to the following:
# “Aggies do not lie, cheat, or steal, or tolerate those who do”
# “I have not given or received any unauthorized aid on this
#assignment”
#
# Name: thien nguyen
# Course/Section: ENGR 289-500
# Assignment: lab10b
# Date: 1 11 2019

import numpy as np

#Weights of each kind of mix in lbs:
mp = 142
ma = 114
mw = 136
mr = 115
mm = 117

#Let A,B,C,D, and E represents Mix 1, Mix 2, Mix 3, Mix 4, and Mix 5 respectively.
A = 0
B = 0
C = 0
D = 0
E = 0

#There are 16 oz in 1 lb, we have weight of each kind of mix in oz: 
mp = 142*16
ma = 114*16
mw = 136*16
mr = 115*16
mm = 117*16

#We have the equations as below: 
#3A+B+C+2D+E = 2272
#A+2B+C+3D+E = 1824 
#A+B+3D+3E = 2176
#2A+3C+D+2E = 2840
#A+2B+3C+2E = 1872

X = np.array([[3,1,1,2,1],[1,2,1,3,1],[1,1,0,3,3],[2,0,3,1,2],[1,2,3,0,2]])
Y = np.array([[A],[B],[C],[D],[E]])
Z = np.array([[mp],[ma],[mw],[mr],[mm]])

X = np.linalg.inv(X)

Y = np.dot(X,Z)

for i in range(len(Y)):
    Y[i] = int(Y[i])

print('The result of the linear equations are: \n', Y)





 

