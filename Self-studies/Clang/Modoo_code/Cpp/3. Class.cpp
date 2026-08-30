#include <iostream>
/* Object-Oriented Language(객체 지향 언어):
** Abstraction(추상화): 현실 세계 반영 -> 직관적
** Encapsulation(캡슐화): Instance Method를 통해 간접적으로 Instance Variable 조절.
** Class,    Member Function, Member Variable
** Instance, Instance Method, Instance Variable
** private 내 변수, 함수는 외부 접근 불가; 'private' 키워드 생략 가능.
** public  내 변수, 함수는 외부 접근 가능.
*/
class Animal {
    private: // private 내 변수, 함수는 외부 접근 불가. (불가: animal.food = 100)
        int food;
        int weight; // food, weight: 멤버 변수
    public:  // public 내 변수, 함수는 외부 접근 가능.
        void set_animal(int _food, int _weight) {
            food = _food;
            weight = _weight;
        }
        void increase_food(int inc) {
            food += inc;
            weight += (inc / 3);
        }
        void view_stat() {
            std::cout << "이 동물의 food : " << food << std::endl;
            std::cout << "이 동물의 weight : " << weight << std::endl;
        } // set_animal, increase_food, view_stat: 멤버 함수 (member function)
}; // 세미콜론

int main() {
    Animal animal; //클래스 Animal의 인스턴스, animal.
    animal.set_animal(100, 50); // public 내 함수들은 공개됨.
    animal.increase_food(30);
    animal.view_stat();
    return 0;
}
