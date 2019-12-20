# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
# By submitting this assignment, I agree to the following:
# “Aggies do not lie, cheat, or steal, or tolerate those who do”
# “I have not given or received any unauthorized aid on this
#assignment”
#
# Name: Thien Nguyen
# Course/Section: ENGR 289-500
# Assignment: lab6b_1
# Date: 05/10/2019


#input
strain = float(input('Please input the strain for the structural steel (0-0.27): '))

#
if 0<=strain<=0.018:
    young_modulus = (42-0)/(0.018-0) #slope 
    b=0 #y-intercept
    stress = young_modulus * strain +b #compute stress
    print('The corressponding stress is: ', stress) #display result
    print(young_modulus)
    
elif 0.018<strain<=0.06:
    young_modulus = (42.8-42)/(0.06-0.018) #slope 
    b = 41.8 #y-intercept
    stress = young_modulus * strain +b #compute stress
    print('The corressponding stress is: ', stress) #display result
    print(young_modulus)
    
elif 0.06<strain<=0.18:
    young_modulus = (60-42.8)/(0.18-0.06) #slope 
    b = 34.2 #y-intercept
    stress = young_modulus * strain +b #compute stress
    print('The corressponding stress is: ', stress) #display result
    print(young_modulus)
    
elif 0.18<strain<=0.27:
    young_modulus = (51-60)/(0.27-0.18) #slope 
    b = 78 #y-intercept
    stress = young_modulus * strain +b #compute stress
    print('The corressponding stress is: ', stress) #display result
    print(young_modulus)
    
else:
    print('Invalid Input...Program is quitting.') #if the user provide invalid input
    
    
