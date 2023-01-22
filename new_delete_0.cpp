#include <iostream>

int main()
{
    int *p = new int; // new as malloc ex) T* pointer =  new T;
    *p = 10;

    std::cout << *p << std::endl;

    delete p; // dlelete as free
    return 0;
}