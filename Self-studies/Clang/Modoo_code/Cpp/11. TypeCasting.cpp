#include <iostream>
/* 삼항 연산자(Ternary Operator): <CONDITION> ? <TRUE_RETURN> : <FALSE_RETURN>
**
**
*/
namespace MyArray {
class Array;
class Int;

class Array {
    friend Int;

    const int dim;
    int* size;
    
    struct Address {
        int level; // level = dim - 1: Int, level < dim - 1: Address pointer
        void* next;
    };

    Address* top;

  public:
    class Iterator {
        int* location;
        Array* arr;
        
        friend Int;

      public:
        Iterator(Array* arr, int* loc = NULL): arr(arr) {
            location = new int[arr->dim];
            for (int i = 0; i != arr->dim; i++)
                location[i] = (loc != NULL ? loc[i] : 0); // 삼항 연산자(Ternary Operator)
        }
        Iterator(const Iterator& itr): arr(arr) {
            location = new int[arr->dim];
            for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];
        }
        ~Iterator() { delete[] location; }

        Iterator& operator++() {
            if (location[0] >= arr->size[0]) return (*this);

            bool carry = false; // 받아 올림이 있는지
            int i = arr->dim - 1;
            do {
                // 어차피 다시 돌아온다는 것은 carry 가 true
                // 라는 의미 이므로 ++ 을 해야 한다.
                location[i]++;
                if (location[i] >= arr->size[i] && i >= 1) {
                    // i 가 0 일 경우 0 으로 만들지 않는다 (이러면 begin 과 중복됨)
                    location[i] -= arr->size[i];
                    carry = true;
                    i--;
                } else
                    carry = false;
                    
            } while (i >= 0 && carry);

            return (*this);
        }
        Iterator& operator=(const Iterator& itr) {
            arr = itr.arr;
            location = new int[itr.arr->dim];
            for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];
            
            return (*this);
        }
        Iterator operator++(int) {
            Iterator itr(*this);
            ++(*this);
            
            return itr;
        }
        bool operator!=(const Iterator& itr) {
            if (itr.arr->dim != arr->dim) return true;
            for (int i = 0; i != arr->dim; i++) {
                if (itr.location[i] != location[i]) return true;
            }

            return false;
        }
        Int operator*();
    };
    
    friend Iterator;
    Array(int dim, int* array_size) : dim(dim) {
        size = new int[dim];
        for (int i = 0; i < dim; i++) size[i] = array_size[i];
        
        top = new Address;
        top->level = 0;

        initialize_address(top);
    }
    Array(const Array& arr) : dim(arr.dim) {
        size = new int[dim];
        for (int i = 0; i < dim; i++) size[i] = arr.size[i];
        
        top = new Address;
        top->level = 0;
        
        initialize_address(top);
    }
    void initialize_address(Address* current) {
        if (!current) return;
        if (current->level == dim - 1) {
            current->next = new int[size[current->level]];
            return;
        }
        current->next = new Address[size[current->level]];
        for (int i = 0; i != size[current->level]; i++) {
            (static_cast<Address*>(current->next) + i)->level = current->level + 1; // current->next를 Address로 형변환
    /*
    C 언어에서 Explict Casting은 다음과 같이 수행됨.
    >   ptr = (Something *)other_ptr;
    >   int_variable = (int)float_variable;
    그러나 위와 같은 타입 캐스팅의 경우 옳지 못한 캐스팅에 대해서 컴파일러가 오류를 발생시키지 않음.
    따라서 실수에 취약. 또한 괄호 안에 타입 넣는 방식은 코드의 가독성이 떨어트림.
    
    C++에서는 4가지 캐스팅을 다음과 같은 문법으로 지원.
    >   static_cast<int>(float_variable);
    • static_cast : 언어적 차원에서 지원하는 일반적인 타입 변환
    • const_cast : 객체의 상수성(const) 를 없애는 타입 변환. 예로, const int 가 int로 바뀐다.
    • dynamic_cast : 파생 클래스 사이에서의 다운 캐스팅
    • reinterpret_cast : 위험을 감수하고 하는 캐스팅으로 서로 관련이 없는 포인터들 사이의 캐스팅 등
    */
            initialize_address(static_cast<Address*>(current->next) + i);
        }
    }
    void delete_address(Address* current) {
        if (!current) return;
        
        if (current->level == dim - 1) {
            delete[] static_cast<int*>(current->next);
        } else {
            for (int i = 0; i < size[current->level]; i++) {
                delete_address(static_cast<Address*>(current->next) + i);
            }
            delete[] static_cast<Address*>(current->next);
        }
        /* 
        for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
            delete_address(static_cast<Address*>(current->next) + i);
        }
        delete[] current->next; delete는 타입을 알아야 작동하는데 처음에 void로
                                정의가 되었으므로 int* 혹은 Address*로 casting
                                하여 실행해야함.

        */
    }
    Int operator[](const int index);
    ~Array() {
        delete_address(top);
        delete[] size;
    }
};
class Int {
    void* data;

    int level;
    Array* array;
    
  public:
    Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL) 
      : level(_level), data(_data), array(_array) {
        if (_level < 1 || index >= array->size[_level - 1]) {
            data = NULL;
            return;
        }
        if (level == array->dim) {
            data = static_cast<void*>((
                static_cast<int*>(static_cast<Array::Address*>(data)->next) + index));
        } else {
            data = static_cast<void*>(static_cast<Array::Address*>(
                                        static_cast<Array::Address*>(data)->next) +
                                    index);
        }
    };

    Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

    operator int() {
        if (data) return *static_cast<int*>(data);
        return 0;
    }
    Int& operator=(const int& a) {
        if (data) *static_cast<int*>(data) = a;
        return *this;
    }
    Int operator[](const int index) {
        if (!data) return 0;
        return Int(index, level + 1, data, array);
    }
};
Int Array::operator[](const int index) {
    return Int(index, 1, static_cast<void*>(top), this);
}
}
int main() {
    int size[] = {2, 3, 4};
    MyArray::Array arr(3, size);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                std::cout << i << " " << j << " " << k << " " << arr[i][j][k]
                << std::endl;
            }
        }
    }
}