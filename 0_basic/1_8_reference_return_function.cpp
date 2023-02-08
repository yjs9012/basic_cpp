// 레퍼런스를 리턴하는 함수
#include <iostream>

class A
{
    int x;

public:
    A(int c) : x(c) {}

    int &access_x() { return x; } // x의 레퍼런스를 리턴
    int get_x() { return x; }
    void show_x() { std::cout << x << std::endl; }
};

int main()
{
    A a(5);
    a.show_x();

    int &c = a.access_x(); // c는 a의 레퍼런스를 받아서 또다른 별명이됨
    c = 4;
    a.show_x();

    int d = a.access_x(); // d는 a의 레퍼런스를 받지만 정수형 변수의므로 d에는 x의 값이 들어가고 값은 안변함
    d = 3;
    a.show_x();

    // 아래는 오류
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();
    // e가 a의 멤버변수를 리턴받기 때문에 레퍼런스를 받아야지만 바꿀수 있음.

    int f = a.get_x();
    f = 1;
    a.show_x();

    a.access_x() = 2;
    a.show_x();
}