def calc_area(type, a, b, c=None):
    if type == 1:
        result = a * b
        msg = 'rectangle' 
    elif type == 2:
        result = a * b /2
        msg = 'triagle'
    elif type == 3:
        result = (a+b)*c/2
        msg = 'parallelogram'
    return result, msg

def say():
    print('calculate area')

def write(result,msg):
    print(msg,' area is', result, 'm2')