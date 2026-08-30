#include <iostream>
#include <ㅊstring>
/*
** 
**
*/
class Complex {
    private:
        double real, img;
        
        double get_number(const char* str, int from, int to);
    public:
        Complex(double real, double img): real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator+(const char* str);
        Complex operator-(const Complex& c);    // 두 객체 간 이항 연산자 적용 시, 한 객체의 멤버 변수만 변경될 경우,
        Complex operator*(const Complex& c);    // 그 객체를 이항연산자의 인자로 받아 overloading을 수행하는 게 좋음.
        Complex operator/(const Complex& c);    // const Complex& c (C++/5. CopyConstructorConst.cpp 참조)

        Complex& operator=(const Complex& c);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        friend Complex operator+(const Complex& a, const Complex& b); //friend: private 내 변수 접근 가능.
        friend std::ostream& operator<<(std::ostream& os, const Complex& c); //타 library 클래스 접근 시
        // std::ostream (iostream이 ostream을 include 하고 있음.) 내에 멤버변수를 만들 수는 없으므로 friend를 
        // 통해 ostream에 멤버 변수에 접근.

        void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "( " << c.real << " , " << c.img << " ) "; // std::cout 또한 std::ostream의 한 객체.
    // 왼쪽 std::cout부터 시작해 이 전역 함수를 거쳐 결과적으로 std::endl;로 마치며 출력될 수 있게.
    return os;
}
Complex::Complex(const char* str) {
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }
    
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);
    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) { return 0; }
    if (str[from] == '-') { minus = true; }
    if (str[from] == '-' || str[from] == '+') { from++; }

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.') {
            integer_part = false;
        } else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else break;
    }
    if (minus) { num *= -1.0; }
    
    return num;
}
Complex Complex::operator+(const Complex& c) {          // 1. 우측 인스턴스만 복사 후, 멤버 변수와 계산 뒤 기존 인스턴스 대체 방식:
    Complex temp(real + c.real, img + c.img);
    return temp;                                        // *this = temp; 좌측 객체의 연산자 오버로딩 이용.
}
Complex operator+(const Complex& a, const Complex& b) { // 2. 두 인스턴스로부터 각각 복사 받아서 계산 뒤 기존 인스턴스 대체 방식:
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;                                        // 좌우 상관없는 연산자 오버로딩 이용.
}                                                       // -> 좌측 객체 또한 const 인자로 받았기에 좌측 객체 private real, img에 접근 가능.
Complex Complex::operator+(const char* str) {
    int begin = 0, end = strlen(str);
    double str_real = 0.0, str_img = 0.0;

    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    if (pos_i == -1) {
        str_real = get_number(str, begin, end - 1);
        Complex temp(str_real, str_img);
        return (*this) + temp;
    }
    
    str_real = get_number(str, begin, pos_i - 1);
    str_img = get_number(str, pos_i + 1, end - 1);
    if (pos_i >= 1 && str[pos_i - 1] == '-') { str_img *= -1.0; }
    Complex temp(str_real, str_img);
    return (*this) + temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp((real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
                 (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img  = c.img;
    return *this;
}
Complex& Complex::operator+=(const Complex& c) {          // 3. 우측 인스턴스만 복사 후, *this keyword로 계산 방식:
    (*this) = (*this) + c;
    return *this;                                         // *this (new) = *this (old); 좌측 객체의 연산자 오버로딩 이용.
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}


int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    Complex c(0.0, 0.0);

    c = a * b + a / b + a + b;
    a += b;
    c.println();
    a.println();
    b.println();

    Complex d(0, 0);
    d = d + "-1.1+i3.923";
    d.println();
    d = d - "1.2 -i1.823";
    d.println();
    d = d * "2.3+i22";
    d.println();
    d = d / "-12+i55";
    d.println();
    std::cout << "d의 값은: " << a << " 이다. " << std::endl;
}