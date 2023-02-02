#include <iostream>
/******************************************************************************
 0. 포인터를 쓰면 의도하지 않은 메모리 접근이 일어날수 있음. -> 함수에서 포인터 사용
    포인터연산이 필요한 경우가 아니면 레퍼런스를 작성해라...?


 1. int& : int형 변수 참조자 | double& : double형 변수 참조자
 2. 레퍼런스는  define과 동시에 initialize 해주어야 함. ex) int& ref_a = a
 3. 한번 다른 변수의 레퍼런스가 되면 다시 바꿀수 없음.
 4. 포인터는 메모리상 8byte이지만, 레퍼런스는 메모리를 차지할수도 있고 안할수도 있다.
 5. (장점) 포인터와 다르게 불필요한 &와 *가 필요없다.
 6. 상수값을 참조하기 위해서는 const int&ref = 4; 와 같이 상수 참조자 선언
******************************************************************************/
int change_val(int *p) // pointer
{
    *p = 7;

    return 0;
}

int main()
{
    int a = 3;
    int &another_a = a; // reference

    another_a = 5;
    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;
    change_val(&a);
    std::cout << "using_pointer_a : " << a << std::endl;

    return 0;
}