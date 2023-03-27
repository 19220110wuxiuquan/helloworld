#include<iostream> 
#include <string>
using namespace std;

class MyString {
private:
    char* str; // 字符串指针
    int length; // 字符串长度
public:
    // 默认构造函数
    MyString() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }


// 有参构造函数
MyString(const char* s) {
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

// 拷贝构造函数
MyString(const MyString& s) {
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
}

// 析构函数
~MyString() {
    delete[] str;
}

// 重载运算符“=”
MyString& operator = (const MyString& s) {
    if (this == &s) {
        return *this;
    }
    delete[] str;
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
    return *this;
}

// 重载运算符“+”
MyString operator + (const MyString& s) {
    MyString newStr;
    delete[] newStr.str;
    newStr.length = length + s.length;
    newStr.str = new char[newStr.length + 1];
    strcpy(newStr.str, str);
    strcat(newStr.str, s.str);
    return newStr;
}

// 重载运算符“==”
bool operator == (const MyString& s) {
    if (length != s.length) {
        return false;
    }
    return strcmp(str, s.str) == 0;
}

// 重载运算符“!=”
bool operator != (const MyString& s) {
    return !(*this == s);
}
}
//
