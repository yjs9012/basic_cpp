// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test
{
    char c;

public:
    Test(char _c)
    {
        c = _c;
        std::cout << "생성자 호출" << c << std::endl;
    }
    ~Test() { std::cout << "소멸자 호출" << c << std::endl; }
};
void simple_function() { Test b('b'); }
int main()
{
    Test a('a');
    simple_function();
    // simple_function 함수가 종료될때 객체'b'가 소멸됨 -> 소멸자 호출
    // main 함수가 종료될때 객체'a'가 소멸됨 -> 소멸자 호출
}
