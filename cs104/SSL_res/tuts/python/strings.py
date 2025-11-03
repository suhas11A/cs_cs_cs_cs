first_name = "John" 
last_name = "Doe"
full_name = first_name + " " + last_name
print("Full Name:", full_name)

age = 25
info_string = "My name is {} and I am {} years old.".format(full_name, age)
print(info_string)

text = "Python is Fun"
print("Upper Case:", text.upper())
print("Lower Case:", text.lower())

message = "   Hello, World!   "
print("Original Message:", message)
print("Stripped Message:", message.strip())

words = ["Python", "is", "an", "amazing", "programming", "language"]
sentence = " ".join(words)
print("Joined Sentence:", sentence)

words = sentence.split()
print("Words in Sentence:", words)

new_sentence = sentence.replace("amazing", "awesome")
print("Original Sentence:", sentence)
print("Modified Sentence:", new_sentence)

