/*
AUTHOR: KAVYA GUPTA
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//DO NOT MODIFY THIS STRUCT (even for debugging)
struct student{
    char* name;
    int marks;
};

void split(string& s, char*& name, int& marks)
{
    int n=s.length(); //length() gives length of string
    int i=-1;
    while(s[++i]!=',')
        name[i] = s[i];
    string marks_string = s.substr(i+1, n-1-i);
    marks = stoi(marks_string); //stoi converts string to integer
}

//DO NOT MODIFY THIS FUNCTION (even for debugging)
//This function compares two entries, don't worry about it.
bool my_compare(student* left, student* right)
{
    if(left->marks > right->marks) return true;
    if(left->marks < right->marks) return false;
    if(strcmp(left->name, right->name)<0) return true;
    return false;
}

int main()
{
    ifstream inputFile("marksheet.csv");
    //ifstream is just a module that helps in file handling in C++.
    string line; vector<student*> entries;
    //"entries" is just a vector (dynamic array) of pointers to many "student" structs.
    int no_of_students = 0;
    cout<<"Starting to read from file :-"<<endl;
    while(getline(inputFile, line))
    {
        //getline function takes lines from the file one-by-one
        //line variable contains each line of input file, starting from the very first.
        ++no_of_students;
        char* student_name; int student_marks;
        split(line, student_name, student_marks);
        student* new_student = new student;
        new_student->name = student_name;
        new_student->marks = student_marks;
        entries.push_back(new_student);
    }
    //This function just sorts the entries, don't worry about it.
    sort(entries.begin(), entries.end(), my_compare);
    cout<<"Now printing :-"<<endl;
    for(int i=0; i<no_of_students; ++i)
    {
        cout<<entries[i]->name<<" "<<entries[i]->marks<<endl;
    }
}