import sys

arg = sys.argv

if (arg[1]=="1"):
    ans=[]
    file = open("translations.csv", "r")
    for line in file:
        lina = line.strip().split(",")
        if lina[0]==arg[2]:
            ans.append(lina[1])
        elif lina[2]==arg[2]:
            ans.append(lina[3])
    file.close()
    ans=list(set(ans))
    ans.sort(reverse=True)
    print(ans)

elif (arg[1]=="2"):
    eng_hin=[]
    eng_pun=[]
    hin_pun=[]
    file = open("translations.csv", "r")
    for line in file:
        lina = line.strip().split(",")
        if lina[0]=="english" and lina[2]=="hindi":
            eng_hin.append((lina[1],lina[3]))
        elif lina[0]=="hindi" and lina[2]=="english":
            eng_hin.append((lina[3],lina[1]))
    file.close()
    file = open("translations.csv", "r")
    for line in file:
        lina = line.strip().split(",")
        if lina[0]=="english" and lina[2]=="punjabi":
            eng_pun.append((lina[1],lina[3]))
        elif lina[0]=="punjabi" and lina[2]=="english":
            eng_pun.append((lina[3],lina[1]))
    file.close()
    file = open("translations.csv", "r")
    for line in file:
        lina = line.strip().split(",")
        if lina[0]=="hindi" and lina[2]=="punjabi":
            hin_pun.append((lina[1],lina[3]))
        elif lina[0]=="punjabi" and lina[2]=="hindi":
            hin_pun.append((lina[3],lina[1]))
    file.close()
    for i in eng_hin:
        for j in hin_pun:
            if i[1]==j[0]:
                eng_pun.append((i[0],j[1]))
    for i in eng_hin:
        for j in eng_pun:
            if i[0]==j[0]:
                hin_pun.append((i[1],j[1]))
    for i in eng_pun:
        for j in hin_pun:
            if i[1]==j[1]:
                eng_hin.append((i[0],j[0]))
    if (arg[2]=="hindi" and arg[3]=="punjabi"):
        ans=hin_pun
    elif (arg[2]=="hindi" and arg[3]=="english"):
        ans=[(x[1],x[0]) for x in eng_hin]
    elif (arg[2]=="english" and arg[3]=="punjabi"):
        ans=eng_pun
    elif (arg[2]=="english" and arg[3]=="hindi"):
        ans=eng_hin
    elif (arg[2]=="punjabi" and arg[3]=="hindi"):
        ans=[(x[1],x[0]) for x in hin_pun]
    elif (arg[2]=="punjabi" and arg[3]=="english"):
        ans=[(x[1],x[0]) for x in eng_pun]
    ans=list(set(ans))
    ans=sorted(ans,key=lambda a:a[0])
    print(ans)
    
elif (arg[1]=="3"):
    eng_hin=[]
    eng_pun=[]
    hin_pun=[]
    file = open("translations.csv", "r")
    for line in file:
        lina = line.strip().split(",")
        if lina[0]=="english" and lina[2]=="hindi":
            eng_hin.append((lina[1],lina[3]))
        elif lina[0]=="hindi" and lina[2]=="english":
            eng_hin.append((lina[3],lina[1]))
    file.close()
    file = open("translations.csv", "r")
    for line in file:
        lina = line.strip().split(",")
        if lina[0]=="english" and lina[2]=="punjabi":
            eng_pun.append((lina[1],lina[3]))
        elif lina[0]=="punjabi" and lina[2]=="english":
            eng_pun.append((lina[3],lina[1]))
    file.close()
    file = open("translations.csv", "r")
    for line in file:
        lina = line.strip().split(",")
        if lina[0]=="hindi" and lina[2]=="punjabi":
            hin_pun.append((lina[1],lina[3]))
        elif lina[0]=="punjabi" and lina[2]=="hindi":
            hin_pun.append((lina[3],lina[1]))
    file.close()
    for i in eng_hin:
        for j in hin_pun:
            if i[1]==j[0]:
                eng_pun.append((i[0],j[1]))
    for i in eng_hin:
        for j in eng_pun:
            if i[0]==j[0]:
                hin_pun.append((i[1],j[1]))
    for i in eng_pun:
        for j in hin_pun:
            if i[1]==j[1]:
                eng_hin.append((i[0],j[0]))
    if (arg[2]=="hindi" and arg[3]=="punjabi"):
        ans=hin_pun
    elif (arg[2]=="hindi" and arg[3]=="english"):
        ans=[(x[1],x[0]) for x in eng_hin]
    elif (arg[2]=="english" and arg[3]=="punjabi"):
        ans=eng_pun
    elif (arg[2]=="english" and arg[3]=="hindi"):
        ans=eng_hin
    elif (arg[2]=="punjabi" and arg[3]=="hindi"):
        ans=[(x[1],x[0]) for x in hin_pun]
    elif (arg[2]=="punjabi" and arg[3]=="english"):
        ans=[(x[1],x[0]) for x in eng_pun]
    ans=list(set(ans))
    ans=sorted(ans,key=lambda a:a[0])
    found=False
    for i in ans:
        if i[0]==arg[4]:
            print(i[1])
            found=True
            break
    if not found:
        print("UNK")
