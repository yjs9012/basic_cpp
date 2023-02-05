#include <iostream>
/******************************************************************************
 1. int&y = x; int&z = y --> int&&z = x(NO) : 참조자의 참조자 만들 필요가 없다.
 2. (Warning) 레퍼런스의 레퍼런스, 레퍼런스의 배열, 레퍼런스의 포인터는 존재할수 없다! ex) int& ref[2]
 3. (Warning) 레퍼런스를 리턴하는 함수에서, 함수내에 정의된 지역변수를 리턴하지 않도록 주의!
 4. (Warinng) 값을      리턴하는 함수에서, const 레퍼런스로 리턴값을 받으면 지역변수 life 연장
 4. 참고 사이트 : https://modoocode.com/141
******************************************************************************/
int &function_a(int &a)
{
    a = 5;
    return a;
}

int function_b()
{
    int a = 5;
    return a;
}

int main()
{
    int x;
    int &y = x;
    int &z = y;

    x = 1;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    y = 2;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    z = 3;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    /***********************************************************************/
    /**********************<References of Arrays>***************************/
    int arr[2] = {1, 2};
    int(&ref)[2] = arr;

    std::cout << "arr[0] : " << arr[0] << " ref[0] : " << ref[0] << std::endl;
    std::cout << "arr[1] : " << arr[1] << " ref[1] : " << ref[1] << std::endl;
    /***********************************************************************/
    /********************<Function return Reference>************************/
    int b = 2;
    std::cout << "b : " << b << std::endl;
    int c = function_a(b);
    std::cout << "b : " << b << " c : " << function_a(b) << std::endl;

    const int &ref_a = function_b();
    std::cout << "ref_a : " << ref_a << std::endl;

    return 0;
}
