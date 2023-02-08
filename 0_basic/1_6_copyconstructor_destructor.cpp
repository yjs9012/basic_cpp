/******************************************************************************
 1. 복사 생성자
    가. 디폴트 복사생성자
        1) 따로 정의해 주지 않아도 아래와 같이 사용가능
           - Marine marine2(marine1);
           - Marine marine2 = marine1;
        2) 클래스 내부에 char* name과 같이 동적할당이 필요한 멤버변수 있을시
           복사를 하게되면 같은 주소값을 가리키게되므로 소멸자 작동시 런타임 오류 발생
           - (얕은 복사) 단순 대입 -> 런타임 오류 발생
           - (깊은 복사) 메모리를 새로 할당해서 대입 -> 오류 발생하지 않음
 ******************************************************************************/

#include <iostream>
#include <string.h>

class Marine
{
private:
  int hp;               // 마린 체력
  int coord_x, coord_y; // 마린 위치
  int damage;           // 공격력
  bool is_dead;
  char *name;

public:
  Marine();                               // 기본 생성자
  Marine(int x, int y, char *input_name); // x, y 좌표에 마린 생성
  Marine(const Marine &mar);              // 복사생성자
  ~Marine();                              // Destructor

  int attack();                      // 데미지를 리턴한다.
  void be_attacked(int damage_earn); // 입는 데미지
  void move(int x, int y);           // 새로운 위치

  void show_status(); // 상태를 보여준다.
};
Marine::Marine()
{
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}
Marine::Marine(int x, int y, char *input_name)
{
  name = new char[strlen(input_name) + 1];
  strcpy(name, input_name);
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
Marine::Marine(const Marine &mar)
{
  std::cout << " 복사 생성자 호출 ! " << std::endl;
  name = mar.name;
  coord_x = mar.coord_x;
  coord_y = mar.coord_y;
  hp = mar.hp;
  damage = mar.damage;
  is_dead = mar.is_dead;
}
Marine::~Marine()
{
  std::cout << name << " 의 소멸자 호출 ! " << std::endl;
  if (name != NULL)
  {
    delete[] name; // 소멸자는 자동으로 되지만 생성당시 할당해주었던 char*에 대한거는 따로 지정해서 소멸시켜 줘야함.
  }
}
void Marine::move(int x, int y)
{
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn)
{
  hp -= damage_earn;
  if (hp <= 0)
    is_dead = true;
}
void Marine::show_status()
{
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main()
{
  Marine *marines[100];

  marines[0] = new Marine(2, 3, "Marine 1");
  marines[1] = new Marine(3, 5, "Marine 2");
  marines[2] = new Marine(*marines[1]);

  marines[0]->show_status();
  marines[1]->show_status();
  marines[2]->show_status();

  std::cout << std::endl
            << "마린 1 이 마린 2 를 공격! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}