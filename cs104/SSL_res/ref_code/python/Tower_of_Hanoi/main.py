'''
    Tower of Hanoi
    Author: Abhi Jain
'''

'''
Write your code to solve tower of hanoi problem here
Take input from user for number of disks

Output format:
line 1: number of moves(N)
line 2: move1
line 3: move2
...
line N+1: moveN
'''

'''
To solve this problem, you can use the recursive approach.
'''

import argparse
n = argparse.ArgumentParser()
n.add_argument("n", type=int)
args = n.parse_args()
n = args.n
n=int(n)
print(2**n-1)

def hana(n,a,b,c):
    if (n==1):
        print(a,b)
        return
    hana(n-1,a,c,b)
    print(a,b)
    hana(n-1,c,b,a)

hana(n,1,3,2)
