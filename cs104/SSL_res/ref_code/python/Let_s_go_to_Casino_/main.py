'''
    Let's go to casino
    Author: Saksham Rathi
'''
import sys
# Please write your code in this file.ok

def f(n):
    one=1
    two=2
    three=4
    four=8
    five=16
    six=32
    x=0
    if n==1:
        print(one)
    elif n==2:
        print(two)
    elif n==3:
        print(three)
    elif n==4:
        print(four)
    elif n==5:
        print(five)
    elif n==6:
        print(six)
    else:
        for i in range(7,n+1):
            x=(one+two+three+four+five+six)%1000000007
            one=two
            two=three
            three=four
            four=five
            five=six
            six=x
        print(x)

m=int(sys.argv[1])
f(m)