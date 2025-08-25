def func(a):
    var1 = a*a # local scope var1
    var2 = 10
    f = var1 + 2

    global var3 # global accesses the globally defined var3
    var3 = 10 # var3 modified in global scope

    return var1

var1 = 20
var3 = 8
print("Before running func", var1, var3)
print("func output", func(2))
print("After running func", var1, var3)
# print(var2) # -- error