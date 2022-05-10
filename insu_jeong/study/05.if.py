# 05.if.py
year = 2020

if(year % 4 == 0) and (year % 100 != 0):    # every 4 years are leaf year and every 100 years are not leaf year
    print(year,"is leaf year.")
elif year % 400 == 0:
    print(year, "is leaf year.")
else:
    print(year, "is not leaf year.")