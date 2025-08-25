'''
    Olympics Medals
    Author: Saksham Rathi
'''

from argparse import ArgumentParser as ap
import os
from functools import cmp_to_key

parser = ap()
parser.add_argument('--path', type=str, required = True)
args = parser.parse_args()

# dictionary for the data
totalData = {}

# looping through the directory
for fileName in os.listdir(args.path):
    with open(os.path.join(args.path,fileName), "r") as file:
        for line in file:
            me=line.strip().split("-")
            if me[0] in totalData.keys():
                totalData[me[0]][0]+=int(me[1])
                totalData[me[0]][1]+=int(me[2])
                totalData[me[0]][2]+=int(me[3])
            else:
                totalData[me[0]]=[int(me[1]),int(me[2]),int(me[3])]
## Method 1
ans=[]
for i,j in totalData.items():
    ans.append((i,j))

def compare_custom(tup1, tup2):
    if tup1[1][0] < tup2[1][0]:
        return 1
    elif tup1[1][0] > tup2[1][0]:
        return -1
    else:
        if tup1[0] < tup2[0]:
            return -1
        elif tup1[0] > tup2[0]:
            return 1
        else:
            return 0

ans = sorted(ans, key=cmp_to_key(compare_custom))
me={}
for i in ans:
    me[i[0]]=i[1]
# print(me)


## Method 2
totalData=sorted(totalData.items(), key=lambda x:(-x[1][0],x[0]))
me={}
for i in ans:
    me[i[0]]=i[1]
print(me)