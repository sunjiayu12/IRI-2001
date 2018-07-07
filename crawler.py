#!/usr/bin/python3
#Filename:TestModule.py
def Hello():
    print ("Hello World")

def Add(a, b):
    print('a=', a)
    print ('b=', b)
    return a + b

class Test:
    def __init__(self):
        print("Init")
    def SayHello(self, name):
        print ("Hello,", name)
        return name
