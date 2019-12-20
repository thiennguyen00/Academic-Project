# By submitting this assignment, I agree to the following:
# “Aggies do not lie, cheat, or steal, or tolerate those who do”
# “I have not given or received any unauthorized aid on this
#assignment”
#
# Name: Thien Nguyen, Alfred Koo, Aref Sadeghi Googhari, Carson Scherkenbach
# Course/Section: ENGR 289-500
# Assignment: lab6_1
# Date: 05/10/2019


gender = input("Please type down your gender. (male, female): ")
while gender != "male" and gender != 'female':
    gender = input("Your input is invalid. Please type in male or 'female': ")

while True:
    try:
        age = int(input("Please enter your age: "))
        while not 24 <= age <= 79:
            age = int(input("The entered age must be between 24 to 79: "))
    except ValueError:
        print("Your age must be a number between 24 to 79:")
        continue
    else:
        break
while True:
    try:
        HDL = float(input('Please enter the HDL level(mg/dL): '))
        while not HDL > 0:
            HDL = float(input("HDL must be greater than 0: "))
    except ValueError:
        print("Please enter a number for your HDL level (mg/dl).")
        continue
    else:
        break
while True:
    try:
        Systolic_BP = float(input('Please enter the Systolic BP level(mmHg): '))
        while not Systolic_BP > 0:
            Systolic_BP = float(input("Systolic_BP must be greater than 0: "))
    except ValueError:
        print("Systolic BP level must be a number: ")
        continue
    else:
        break
treat = input('If treated, please enter 1, if not enter 0: ')
while not treat == '1' and not treat == '0':
    treat = input("Please enter 1 for treated and 0 for not treated: ")
if treat == '1' or treat == '0':
    treat = int(treat)
while True:
    try:
        Total_Cholesterol = float(input('Please input the total cholesterol: '))
        while not Total_Cholesterol > 0:
            Total_Cholesterol = float(input('The total cholesterol must be greater than 0: '))
    except ValueError:
        print("The total Cholesterol must be a number.")
        continue
    else:
        break
smoker = input("Please enter Y for smoker and N for non-smoker: ")
while smoker != 'Y' and smoker != 'N':
    smoker = input("Please enter Y for smoker and N for non-smoker: ")
total_points = 0
if gender == "male":
    if 20 <= age <= 34:
        total_points = -9
    elif 35 <= age <= 39:
        total_points = -4
    elif 40 <= age <= 44:
        total_points = 0
    elif 45 <= age <= 49:
        total_points = 3
    elif 50 <= age <= 54:
        total_points = 6
    elif 55 <= age <= 59:
        total_points = 8
    elif 60 <= age <= 64:
        total_points = 10
    elif 65 <= age <= 69:
        total_points = 11
    elif 70 <= age <= 74:
        total_points = 12
    elif 75 <= age <= 79:
        total_points = 13
    # HDL test

    if HDL >= 60:
        total_points += -1
    elif 50 <= HDL <= 59:
        total_points += 0
    elif 40 <= HDL <= 49:
        total_points += 1
    elif HDL < 40:
        total_points += 2

    # Systolic test

    # 1
    if Systolic_BP < 120:
        if treat == 0:
            total_points += 0
        else:
            total_points += 0

    # 2
    if 120 <= Systolic_BP <= 129:
        if treat == 0:
            total_points += 0
        else:
            total_points += 1

    # 3
    if 130 <= Systolic_BP <= 139:
        if treat == 0:
            total_points += 1
        else:
            total_points += 2

    # 4
    if 140 <= Systolic_BP <= 159:
        if treat == 0:
            total_points += 1
        else:
            total_points += 2

    # 5
    if 160 <= Systolic_BP:
        if treat == 0:
            total_points += 2
        else:
            total_points += 3

    # total cholesterol test

    if 20 <= age <= 39:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 4
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 7
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 9
        elif 280 <= Total_Cholesterol:
            total_points += 11

    if 40 <= age <= 49:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 3
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 5
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 6
        elif 280 <= Total_Cholesterol:
            total_points += 8

    if 50 <= age <= 59:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 2
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 3
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 4
        elif 280 <= Total_Cholesterol:
            total_points += 5

    if 60 <= age <= 69:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 1
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 1
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 2
        elif 280 <= Total_Cholesterol:
            total_points += 3

    if 70 <= age <= 79:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 0
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 0
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 1
        elif 280 <= Total_Cholesterol:
            total_points += 1

    if smoker == 'Y':
        if 20 <= age <= 39:
            total_points += 8
        if 40 <= age <= 49:
            total_points += 5
        if 50 <= age <= 59:
            total_points += 3
        if 60 <= age <= 69:
            total_points += 1
        if 70 <= age <= 79:
            total_points += 1
    ############################
    Total_points = total_points

    if Total_points < 0:
        print('The 10-year risk is <1% ')
    elif 0 <= Total_points <= 0:
        print('The 10-year risk is 1%')
    elif 5 <= Total_points <= 6:
        print('The 10-year risk is 2%')
    elif Total_points == 7:
        print('The 10-year risk is 3%')
    elif Total_points == 8:
        print('The 10-year risk is 4%')
    elif Total_points == 9:
        print('The 10-year risk is 5%')
    elif Total_points == 10:
        print('The 10-year risk is 6%')
    elif Total_points == 11:
        print('The 10-year risk is 8%')
    elif Total_points == 12:
        print('The 10-year risk is 10 %')
    elif Total_points == 13:
        print('The 10-year risk is 12%')
    elif Total_points == 14:
        print('The 10-year risk is 16%')
    elif Total_points == 15:
        print('The 10-year risk is 20%')
    elif Total_points == 16:
        print('The 10-year risk is 25%')
    elif Total_points >= 17:
        print('The 10-year risk is 30%')

#########################################

elif gender == "female":
    if 20 <= age <= 34:
        total_points = -7
    elif 35 <= age <= 39:
        total_points = -3
    elif 40 <= age <= 44:
        total_points = 0
    elif 45 <= age <= 49:
        total_points = 3
    elif 50 <= age <= 54:
        total_points = 6
    elif 55 <= age <= 59:
        total_points = 8
    elif 60 <= age <= 64:
        total_points = 10
    elif 65 <= age <= 69:
        total_points = 12
    elif 70 <= age <= 74:
        total_points = 14
    elif 75 <= age <= 79:
        total_points = 16
    # HDL test

    if HDL >= 60:
        total_points += -1
    elif 50 <= HDL <= 59:
        total_points += 0
    elif 40 <= HDL <= 49:
        total_points += 1
    elif HDL < 40:
        total_points += 2

    # Systolic test

    # 1
    if Systolic_BP < 120:
        if treat == 0:
            total_points += 0
        else:
            total_points += 0

    # 2
    if 120 <= Systolic_BP <= 129:
        if treat == 0:
            total_points += 1
        else:
            total_points += 3

    # 3
    if 130 <= Systolic_BP <= 139:
        if treat == 0:
            total_points += 2
        else:
            total_points += 4

    # 4
    if 140 <= Systolic_BP <= 159:
        if treat == 0:
            total_points += 3
        else:
            total_points += 5

    # 5
    if 160 <= Systolic_BP:
        if treat == 0:
            total_points += 4
        else:
            total_points += 6

    # total cholesterol test

    if 20 <= age <= 39:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 4
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 8
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 11
        elif 280 <= Total_Cholesterol:
            total_points += 13

    if 40 <= age <= 49:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 3
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 8
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 6
        elif 280 <= Total_Cholesterol:
            total_points += 10

    if 50 <= age <= 59:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 2
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 4
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 5
        elif 280 <= Total_Cholesterol:
            total_points += 7

    if 60 <= age <= 69:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 1
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 2
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 3
        elif 280 <= Total_Cholesterol:
            total_points += 4

    if 70 <= age <= 79:
        if Total_Cholesterol < 160:
            total_points += 0
        elif 160 <= Total_Cholesterol <= 199:
            total_points += 1
        elif 200 <= Total_Cholesterol <= 239:
            total_points += 1
        elif 240 <= Total_Cholesterol <= 279:
            total_points += 2
        elif 280 <= Total_Cholesterol:
            total_points += 2

    if smoker == 'Y':
        if 20 <= age <= 39:
            total_points += 9
        if 40 <= age <= 49:
            total_points += 7
        if 50 <= age <= 59:
            total_points += 4
        if 60 <= age <= 69:
            total_points += 2
        if 70 <= age <= 79:
            total_points += 1
    ############################
    Total_points = total_points

    if Total_points < 9:
        print('The 10-year risk is <1% ')
    elif 9 <= Total_points <= 12:
        print('The 10-year risk is 1%')
    elif 13 <= Total_points <= 14:
        print('The 10-year risk is 2%')
    elif Total_points == 15:
        print('The 10-year risk is 3%')
    elif Total_points == 16:
        print('The 10-year risk is 4%')
    elif Total_points == 17:
        print('The 10-year risk is 5%')
    elif Total_points == 18:
        print('The 10-year risk is 6%')
    elif Total_points == 19:
        print('The 10-year risk is 8%')
    elif Total_points == 20:
        print('The 10-year risk is 11%')
    elif Total_points == 21:
        print('The 10-year risk is 14%')
    elif Total_points == 22:
        print('The 10-year risk is 17%')
    elif Total_points == 23:
        print('The 10-year risk is 22%')
    elif Total_points == 24:
        print('The 10-year risk is 27%')
    elif Total_points >= 25:
        print('The 10-year risk is 30%')
