#include <iostream>

typedef struct Animal
{
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal *animal)
{
    std::cout << "What is name of animal?";
    std::cin >> animal->name;
    std::cout << "What is age of animal?";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal)
{
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}
void one_day_pass(Animal *animal)
{
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}
void show_stat(Animal *animal)
{
    std::cout << animal->name << "'s status'" << std::endl;
    std::cout << "Health    : " << animal->health << std::endl;
    std::cout << "Food      : " << animal->food << std::endl;
    std::cout << "Clean     : " << animal->clean << std::endl;
}

int main()
{
    Animal *list[10]; // list[10]은 메모리영역에 할당되어 있음 list[11]생성되게되면 오류 발생
    int animal_num = 0;

    for (;;)
    {
        std::cout << "1. Add animal" << std::endl;
        std::cout << "2. Play" << std::endl;
        std::cout << "3. Get status" << std::endl;

        int input;
        std::cin >> input;

        switch (input)
        {
            int play_with;
        case 1:
            list[animal_num] = new Animal; // heap영역에 메모리 동적할당
            create_animal(list[animal_num]);

            animal_num++;
            break;
        case 2:
            std::cout << " Who play with?";
            std::cin >> play_with;

            if (play_with < animal_num)
                play(list[play_with]);
            break;
        case 3:
            std::cout << "Who's status want to get?";
            std::cin >> play_with;

            if (play_with < animal_num)
                show_stat(list[play_with]);
            break;
        default:
            break;
        }
        for (int i = 0; i != animal_num; i++)
        {
            one_day_pass(list[i]);
        }
    }
    for (int i = 0; i != animal_num; i++)
    {
        delete list[i];
    }
}
