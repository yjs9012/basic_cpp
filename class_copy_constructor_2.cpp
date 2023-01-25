#include <string.h>
#include <iostream>

class Photon_Cannon
{
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon &pc);
    ~Photon_Cannon();

    void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y)
{
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name)
{
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc)
{
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}
Photon_Cannon::~Photon_Cannon()
{
    // 0 이 아닌 값은 if 문에서 true 로 처리되므로
    // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name != 0) 과 동일한 의미를 가질 수 있다.

    // 참고로 if 문 다음에 문장이 1 개만 온다면
    // 중괄호를 생략 가능하다.

    if (name)
        delete[] name;
    std::cout << "constructor 일했다 " << std::endl;
}
void Photon_Cannon::show_status()
{
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main()
{
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2(pc1);  // deep copy -> 메모리를 새로 할당하기때문에 리턴시 오류가 없음
    Photon_Cannon pc3 = pc2; // shallow copy -> name이 같은 주소를 가르켜 메모리 리턴시 오류

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();
}