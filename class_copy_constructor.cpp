// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon
{
    int hp, shield;
    int coord_x, coord_y;
    int damage;

public:
    Photon_Cannon();
    Photon_Cannon(int x, int y);
    Photon_Cannon(const Photon_Cannon &pc); // copy_constructor Type(const Type& a)

    void show_status();
};
/**********************************************************/
Photon_Cannon::Photon_Cannon()
{
    std::cout << "디폴트 생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = 5;
    coord_y = 5;
    damage = 20;
}
Photon_Cannon::Photon_Cannon(int x, int y)
{
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc)
{
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
/**********************************************************/
void Photon_Cannon::show_status()
{
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
/**********************************************************/
int main()
{
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);              // copy_constructor
    Photon_Cannon pc3 = pc2;             // pc3(pc2)
    Photon_Cannon pc4;                   // default_constructor : pc4()
    Photon_Cannon pc5 = Photon_Cannon(); // default_constructor : pc5()

    pc4 = pc3; // substitute pc4 to pc3

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();
    pc4.show_status();
    pc5.show_status();
}