import numpy as np

a= np.zeros((2,5), np.int)
b = np.ones((3,1), np.uint8)
c = np.empty((1,5), np.float)
d = np.full(5,15,np.float32)

print('c shape:', c.shape, ', d shape:', d.shape)
print(a), print(b)
print(c), print(d)