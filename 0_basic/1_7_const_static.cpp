/******************************************************************************
 1. 생성자 초기화 리스트(initializer list)
    Classname() : member(arg), memeber2(arg2), memeber3(arg3), memeber4(arg4){}
    - 생성자 int a; a = 10;
    - 초기화 리스트 int a = 10; 즉 생성과 대입을 동시에 해줌
 2. Static 멤버변수
    - 클래스 내부에 정의된 static 변수들은 0으로 초기화 해주어야 함.
    - 멤버변수들을 클래스 정의에서 초기화 시키지 못하는것처럼, static 변수도 함수로 정의해주어야함
 3. Static 멤버 함수
    - 인스턴스를 만들지 않고도 클래스 자체에서 호출
    - 클래스에 종속된것이기 때문에 호출하는 방법이 일반 함수와 다름
       ex) Marine::show_total_number();
 ******************************************************************************/
#include <iostream>

class Marine
{
    static int total_marine_num; // static 변수 정의

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage; // const를 통한 디폴트 값

public:
    Marine();             // 기본 생성자
    Marine(int x, int y); // x, y 좌표에 마린 생성
    Marine(int x, int y, int default_damage);

    int attack();                      // 데미지를 리턴한다.
    void be_attacked(int damage_earn); // 입는 데미지
    void move(int x, int y);           // 새로운 위치

    void show_status(); // 상태를 보여준다.
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine()
{
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false)
{
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false)
{
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false)
{
    total_marine_num++;
}

void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
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
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine()
{
    Marine marine3(10, 10, 4);
    Marine::show_total_marine();
}
int main()
{
    Marine marine1(2, 3, 5);
    Marine::show_total_marine();

    Marine marine2(3, 5, 10);
    Marine::show_total_marine();

    create_marine();

    std::cout << std::endl
              << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}