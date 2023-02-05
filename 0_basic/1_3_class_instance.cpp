/******************************************************************************
 1. An Object(객체) is composed with (instance) variables and (instance) Methods.
 2. Encapsulation : 인스턴스 내의 변수를 바꿀때 외부에서 직접접근은 불가!
                    인스턴스 메소드를 통해서 간접적으로 조절
 3. An Class(클래스) : 객체의 설계도 / 빈 껍질
                       클래스로 만들어진 객체를 인스턴스라고 부름
 4. private는 객체 내에서만 접근가능 / public은 객체 외부에서 접근가능
 ******************************************************************************/
#include <iostream>

class Animal // Define Class Animal
{
private: // 멤버변수
   int food;
   int weight;

public: // 멤버함수
   void SetAnimal(int _food, int _weight)
   {
      food = _food;
      weight = _weight;
   }
   void IncreaseFood(int inc)
   {
      food += inc;
      weight += (inc / 3);
   }
   void ViewStat()
   {
      std::cout << "이 동물의 food   : " << food << std::endl;
      std::cout << "이 동물의 weight : " << weight << std::endl;
   }
};

int main()
{
   Animal animal; // Declare instance animal which is class of Animal;
   animal.SetAnimal(100, 50);
   animal.IncreaseFood(20);
   animal.ViewStat();
   return 0;
}