import numpy as np
import cv2

# dictonary
switch_case = {
    ord('a'): "a key enter", # ord() function : spell -> ascii code transpormation
    ord('b'): "b key enter",
    ord('A'): "A key enter",
    int('0x42', 16): "B key enter",
    37: "left arrow",
    38: "up arrow",
    39: " right arrow",
    40: "down arrow"
}

image = np.ones((200,300), np.float)
cv2.namedWindow('Keyboard Event')
cv2.imshow("Keyboard Event", image)

while True:
    key = cv2.waitKeyEx(100)
    if key == 27: break # ESC key end this program

    try:
        result = switch_case[key]
        print(key)
        print(result)
    except KeyError:
        result= -1
cv2.destroyAllWindows()