# Defining a class
class Car:
    # Class variable (shared among all instances)
    wheels = 4  
    
    # Constructor (__init__) to initialize instance variables
    def __init__(self, brand, color, year):
        self.brand = brand  # Instance variable
        self.color = color  # Instance variable
        self.year = year    # Instance variable
        self.features = []  # Instance variable to store car features
    
    # Method to display car details
    def car_info(self):
        return f"{self.color} {self.brand} ({self.year}) with {Car.wheels} wheels"

    # Overriding __str__ method for user-friendly output
    def __str__(self):
        return f"Car: {self.brand}, Color: {self.color}, Year: {self.year}"

    # Implementing __len__ method to return number of features
    def __len__(self):
        return len(self.features)

    # Implementing __getitem__ method to get feature by index
    def __getitem__(self, index):
        return self.features[index]

    # Method to add feature to the car
    def add_feature(self, feature):
        self.features.append(feature)


# Class without __str__ method overridden
class CarWithoutStr:
    def __init__(self, brand, color, year):
        self.brand = brand
        self.color = color
        self.year = year
        self.features = []

  

# Creating objects (instances of the Car classes)
car1 = Car("Toyota", "Red", 2022)  # Uses overridden __str__
car2 = CarWithoutStr("Honda", "Blue", 2020)  # Uses default __str__

# Adding features to car1 and car2
car1.add_feature("Sunroof")
car1.add_feature("Leather seats")
car1.add_feature("Alloy Wheels")


# Printing objects using __str__ method
print(car1)  # Output: Car: Toyota, Color: Red, Year: 2022
print(car2)  # Output: <__main__.CarWithoutStr object at 0x...> (default object representation)

# Using __len__ to get the number of features
print(len(car1))  # Output: 2 (features of car1)


# Using __getitem__ to access features by index
print(car1[0])  
print(car1[1])  

