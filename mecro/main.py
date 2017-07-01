#-*- coding: utf-8 -*-
import serial
import Macro
import webbrowser
from os import system


print "SET MECRO"
#메모장의 내용 저장
arr = []
file = open("list.txt",'r')
for x in range(0,16):
    temp = file.readline()
    print temp[0:1]
    if temp[0:1]=="#":
        arr.append([1,temp[1:-1]])
    elif temp[0:1]==":":
        arr.append([2,temp[1:-1]])
    elif temp[0:1]=="!":
        arr.append([3,temp[1:-1]])
    else:
        arr.append([1, "Blank"])

for x in arr:
    print(x)

arduino = serial.Serial('COM5',9600) # 시리얼 통신 받아옴

while(True):
    a = arduino.readline()
    num = int(a[0:2])
    if arr[num-1][0] == 1:
        Macro.main((arr[num-1][1]))
    elif arr[num-1][0] == 2:
        webbrowser.open(arr[num-1][1])
    elif arr[num-1][0] == 3:
        Macro.Press(arr[num-1][1])
    else:
        pass
