# Conditionals Demonstration
x = 10
y = 5

# Simple if condition
if x > y:
    print("x is greater than y")

# if-else condition
if x < y:
    print("x is less than y")
else:
    print("x is not less than y")

# if-elif-else condition
num = 0
if num > 0:
    print("Positive number")
elif num < 0:
    print("Negative number")
else:
    print("Zero")

# Loop Demonstrations

# for loop using range()
print("\nFor loop with range(5):")
for i in range(5):  # range(5) generates numbers 0 to 4
    print(i)

# for loop with range(start, stop, step)
print("\nFor loop with range(1, 10, 2):")
for i in range(1, 10, 2):  # start at 1, go up to 10, step by 2
    print(i)

# for loop with range using a negative step
print("\nFor loop with range(10, 0, -2):")
for i in range(10, 0, -2):  # start at 10, go down to 0, step by -2
    print(i)

# while loop
print("\nWhile loop example:")
count = 0
while count < 5:
    print(count)
    count += 1  # Increment to avoid infinite loop

# break statement in a loop
print("\nLoop with break:")
for i in range(10):
    if i == 5:
        print("Breaking at", i)
        break
    print(i)

# continue statement in a loop
print("\nLoop with continue:")
for i in range(5):
    if i == 2:
        print("Skipping", i)
        continue
    print(i)

# pass statement (used when a block of code is required syntactically but no action is needed)
print("\nLoop with pass:")
for i in range(5):
    if i == 2:
        pass  # Placeholder for future code
    print(i)
