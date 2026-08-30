#include <iostream>

class Test {
    int x;

public:
    Test(int x) : x(x) {}
    Test(const Test& t) : x(t.x) {}

    Test& operator++() { // 전위 연산자는 operator++ or operator-- 이후 ()
        x++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }
    Test& operator++(int) { // 후위 연산자는 operator++ or operator-- 이후 (int)
        x++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }
    int get_x() const { return x; }
};

int main() {
    Test t(3);

    func(++t);
    func(t++);
    std:: << "x: " << t.get_x() << std::endl;
}