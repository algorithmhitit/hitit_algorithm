list1= [1,2,3,4,]
print(list1)
list2 = [1, 1.5, 'a', 'a', 'string']
tuple1 = (1,2)
tuple2 = (1, 1.5, 'a', 'a', 'string')
dict1 = { 'name': 'beajongwook', 'email': 'daum.net'}
set1, set2 = set(list2), set(tuple2)

list2.insert(3,'b')
dict1['email'] = 'naver.com'

print('dict1', dict1, type(dict1))