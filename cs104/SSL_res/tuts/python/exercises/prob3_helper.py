'''
You are given a folder named students, which has information about the courses undertaken and grade 
scored, for each student in different file. Your task is to create a function, which takes in two 
arguments, the file path and branch change preferences, and prints the results of branch change on 
terminal.
Hint: You can import the branch_change
'''

from branch_change import *

def my_func(file_path, branch_pref):
    # TODO: Write your code here
    pass

if __name__ == "__main__":
    filepath = "students/Sahil.txt"
    branch_pref = ["CSE", "EE", "ME"]
    print("Branch change attempted for student Sahil")
    print("Branch Preferences: ", branch_pref)
    new_major = my_func(filepath, branch_pref)
    if new_major == None:
        print("Sorry, you cannot branch change.")
    else:
        print("Congratulations! You successfully branch changed to " + new_major + " dept.")


