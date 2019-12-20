# By submitting this assignment, I agree to the following:
# “Aggies do not lie, cheat, or steal, or tolerate those who do”
# “I have not given or received any unauthorized aid on this
#assignment”
#
# Name: Thien Nguyen, Alfred Koo, Aref Sadeghi Googhari, Carson Scherkenbach
# Course/Section: ENGR 289-500
# Assignment: lab9b_act2
# Date: 10/25/2019

file1 = open('LabAssignment9b_fake_names_and_IDs_data.txt')

file2 = open('lab9b_act2.txt', 'w')


row = file1.readline()

data3 = []

for line in file1:  
    data3 += [line.split()]
    
f_name = []

l_name = []

email_list = []

first_name = []

last_name = []

three_digit = []

tail = '@gmail.com'

sum = []

sum1 = 0

for i in range(len(data3)):
    f_name += [data3[i][0]]
    
for i in range(len(data3)):
    l_name += [data3[i][1]]


for i in range(len(data3)):
    first_name += [data3[i][0]]

for i in range(len(first_name)):
    first_name[i] = first_name[i][0]

for i in range(len(data3)):
    last_name += [data3[i][1]]
    
for i in range(len(last_name)):
    last_name[i] = last_name[i].lower()

for i in range(len(data3)):
    three_digit += [data3[i][2]]

for i in range(len(three_digit)):
    sum1 = str(int(three_digit[i][2:5])*2) 
    sum += [sum1]

for i in range(len(sum)):
    if (len(sum[i])==1):
        sum[i] = '00' + sum[i]
    if (len(sum[i])==2):
        sum[i] = '0' + sum[i]
    if (len(sum[i])==4):
        sum[i] = sum[i].replace(sum[i][0],'')
        
for i in range(len(first_name)):
    email_list += [first_name[i] + last_name[i] + sum[i] + tail]

f_name.insert(0,'firstname')
l_name.insert(0,'lastname')
email_list.insert(0,'email')
    
for i in range(len(f_name)):
    print(f_name[i].ljust(10), l_name[i].ljust(10),email_list[i].ljust(10),  file=file2)

file1.close()
file2.close()
