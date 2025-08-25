# Python, being an OOP language, allows us to define classes, like in C++
# Some built-in functions of a class are __init__ and __str__
from branch_change import branch_change as bc

# We define a class for a Student
class Student:
    def __init__(self, name, major):
        self.name = name
        self.major = major
        self.cpi = 0
        self.credits = 0
    
    def __str__(self):
        return self.name + ", " + self.major + " dept."

    def get_cpi(self):
        return self.cpi

    def add_course(self, num_credits, grade):
        self.credits += num_credits
        self.cpi = (self.cpi*(self.credits - num_credits) + num_credits*grade)/self.credits

    def branch_change(self, branch_prefs):
        new_major = bc(self.cpi, branch_prefs)
        if new_major == None:
            print("Sorry, you cannot branch change.")
        else:
            print("Congratulations! You successfully branch changed to " + new_major + " dept.")
            self.major = new_major
    
    
if __name__ == "__main__":

    student1 = Student("Rohan", "CSE")
    student2 = Student("Sabya", "EE")
    student3 = Student("Rohit", "ME")
    student4 = Student("Sahil", "CE")

    students = [student1, student2, student3, student4]

    for student in students:
        print(student)
    print("-----------------------------------")

    student1.add_course(4, 9)
    student2.add_course(4, 8)
    student3.add_course(4, 7)
    student4.add_course(4, 10)

    for student in students:
        print(f"{student.name} has cpi {student.cpi}")
    print("-----------------------------------")

    student2.add_course(6, 9)
    student2.add_course(4, 8)
    student2.add_course(8, 7)

    print(f"{student2.name} has cpi {student2.cpi}")
    print(f"{student2.name} is in {student2.major} dept.")
    print("-----------------------------------")
    # Attempt branch change
    branch_preferences = ["CSE", "EE", "ME", "CE", "CHE", "ENV", "BSBE"]
    print(f"{student2.name} is attempting branch change.")
    student2.branch_change(branch_preferences)
    print(f"{student2.name} is in {student2.major} dept.")
    print("-----------------------------------")




        


