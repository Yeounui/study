#include <iostream>
/* explict: prevent implicit conversion.
** 생성자와 변환 연산자(Conversion Operator)에 적용 가능하며, 명시적 형 변환만 허용시킴.
** MyString s(5);  DoSomethingWithString(MyString s):
**      - 인자로 int를 받음(명시적). int를 인자로 받는 생성자로 MyString 인스턴스 생성 후, DoSomethingWithString 적용.
** MyString s = 5; DoSomethingWithString(MyString s): Explicit에 의해 에러;
**      - MyString s = 5 -> int 인자를 받는 생성자가 있는 지 확인 (에러: 묵시적 형 변화) 후, 인스턴스 생성. 이후 DoSomethingWithString 적용.
**/
class MyString {
    char* string_content;
    int string_length;
    int memory_capacity;

public:
    MyString(int capacity); // work
    //explict MyString(int capacity); // not work

    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    int length() const;
    int capacity() const;
};

MyString::MyString(int capacity){
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
}
MyString::MyString(const char* str){
    string_length = 0;
    while (str[string_length++]){
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) { string_content[i] = str[i]; }
}
MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) { string_content[i] = str.string_content[i]; }
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void DoSomethingWithString(MyString s){

}

int main() {
    MyString s(3);

    DoSomethingWithString(3);
/*      MyString s(5);  works (int input.)
**      MyString s = 5; not work */
}
