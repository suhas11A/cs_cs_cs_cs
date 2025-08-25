#include <iostream>
#include <stdexcept>
#include <cassert>

class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString() : data(new char('\0')), length(0) {}

    // Constructor from C-string
    MyString(const char* str) {
        length = 0;
        while (str[length] != '\0') ++length;
        data = new char[length + 1];
        for (size_t i = 0; i < length; ++i) data[i] = str[i];
        data[length] = '\0';
    }

    // Copy constructor
    MyString(const MyString& other) : length(other.length), data(new char[other.length + 1]) {
        for (size_t i = 0; i < length; ++i) data[i] = other.data[i];
        data[length] = '\0';
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy assignment
    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        length = other.length;
        delete[] data;
        data = new char[length + 1];
        for (size_t i = 0; i < length; ++i) data[i] = other.data[i];
        data[length] = '\0';
        return *this;
    }

    // Concatenation
    MyString operator+(const MyString& other) const {
        MyString newStr;
        newStr.length = length + other.length;
        newStr.data = new char[newStr.length + 1];
        size_t p = 0;
        for(; p < length; p++)
            newStr[p] = data[p];
        for(; p < newStr.length; p++)        
            newStr[p] = other.data[p - length];
        newStr.data[newStr.length] = '\0';
        return newStr;
    }

    // Compound concatenation
    MyString& operator+=(const MyString& other) {
        char* newData = new char[length + other.length + 1];
        size_t p = 0;
        for(; p < length; p++)
            newData[p] = data[p];
        for(; p < length + other.length ; p++)        
            newData[p] = other.data[p - length];
        newData[p] = '\0';
        delete[] data;
        data = newData;
        length += other.length;
        return *this;
    }

    // Subscript operator
    char& operator[](size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Comparison operators
    bool operator==(const MyString& other) const {
        if (length != other.length) return false;
        for (size_t i = 0; i <= length; ++i) if (data[i] != other.data[i]) return false;
        return true;
    }
    bool operator!=(const MyString& other) const { return !(*this == other); }
    bool operator<(const MyString& other) const {
        size_t minLength = length < other.length ? length : other.length; 
        for (size_t i = 0; i < minLength; ++i) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return length < other.length;
    }
    bool operator>(const MyString& other) const { return other < *this; }

    // Substring extraction
    MyString substr(size_t pos, size_t len) const {
        if (pos+len-1 >= length) throw std::out_of_range("Position out of range");
        char* sub = new char[len + 1];
        for (size_t i = 0; i < len; ++i) sub[i] = data[pos + i]; 
        sub[len] = '\0';
        return sub;
    }

    // Length getter
    size_t size() const { return length; }

    // C-string getter
    const char* c_str() const { return data; }

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.data;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, MyString& str) {      //change this : remove reference
        char* buffer = new char[100];
        is >> buffer;
        str = MyString(buffer);
        delete[] buffer;
        return is;
    }

    // Iterator support
    char* begin() { return data; }
    char* end() { return data + length; }
};  