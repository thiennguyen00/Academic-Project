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
import matplotlib.pyplot as plt

file1 =open ('weather_file.txt')

data = []

row = file1.readline()

    
temp_avg = []

pressure = []

date = []

temperature2 = []

temperature_high2 = []

temperature_low2 = []

precipitation = []


dew_point = []

sum = 0
mean = 0

counter = 0

max = 41

min = 35

c = 0

for line in file1:  
    data += [line.split(',')]

for i in range(len(data)):
    temp_avg += [float(data[i][2])]
    
for i in range(len(data)):
    pressure += [float(data[i][11])]

for i in range(len(data)):
    date += [data[i][0]]

for i in range(len(data)):
    precipitation += [data[i][13]]

for i in range(len(data)):
    dew_point += [data[i][5]]

for row in range(len(data)):
    sum += int(data[row][2])
        
    if (row % 30 == 0):
        mean = sum/30
        temperature2 += [int(mean)]
        sum = 0


for row in range(len(data)):
    if (int(max) < int(data[row][1])):
        max = data[row][1]
        
    if (row % 30 == 0):
        temperature_high2 += [int(max)]
        max = 0
        
            
       

for row in range(len(data)):
    if (int(min) > int(data[row][3])):
        min = data[row][3]
    if (row % 30 == 0):
        temperature_low2 += [int(min)]
        min = 200
        
        
    

#a)
fig = plt.figure()
plt.plot(date, temp_avg, pressure)
#plt.plot(date, pressure, color='tab:orange')
plt.xlabel('date')
plt.ylabel('temp_avg and pressure')
plt.title('average temperature and pressure vs time')

plt.show()

#b)
plt.hist(precipitation, bins=20)
plt.xlabel('precipiations')
plt.ylabel('number of day')
plt.title('precipitation vs number of day')

plt.show()

#c)
plt.scatter(temp_avg, dew_point, c=('blue'))
plt.title('temperature vs dew point')
plt.xlabel('temperature')
plt.ylabel('dew point')
plt.show()

#d)
n_groups = 37

# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.35
opacity = 0.8

rects1 = plt.bar(index, temperature2, bar_width,
alpha=opacity,
color='b',
label='average temperature')

rects2 = plt.bar(index + bar_width, temperature_high2, bar_width,
alpha=opacity,
color='g',
label='high temperature')

rects3 = plt.bar(index + bar_width + bar_width, temperature_low2, bar_width,
alpha=opacity,
color='orange',
label='low temperature')

plt.xlabel('Months')
plt.ylabel('Temperatures')
plt.title('Average Temperature, high temperature, and low temperature vs month')
plt.legend()

plt.show()



    


