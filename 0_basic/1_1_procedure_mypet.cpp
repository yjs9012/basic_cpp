#include <iostream>

typedef struct Animal
{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

void createAnimal(Animal *animal)
{
    std::cout << "What is a animal's name?";
    std::cin >> animal->name;

    std::cout << "How old animal's age?";
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

void passDay(Animal *animal)
{
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void showStat(Animal *animal)
{
    std::cout << "Name   : " << animal->name << std::endl;
    std::cout << "Age    : " << animal->age << std::endl;
    std::cout << "Health : " << animal->health << std::endl;
    std::cout << "Food   : " << animal->food << std::endl;
    std::cout << "Clean  : " << animal->clean << std::endl;
}

int main()
{
    Animal *list[10];
    int animal_num = 0;

    for (;;)
    {
        std::cout << "1. Add an animal" << std::endl;
        std::cout << "2. Play " << std::endl;
        std::cout << "3. Show status " << std::endl;

        int input;
        std::cin >> input;

        switch (input)
        {
            int playWith;
        case 1:
            list[animal_num] = new Animal;
            createAnimal(list[animal_num]);
            animal_num++;
            break;

        case 2:
            std::cout << "Who do you want to play with? :";
            std::cin >> playWith;
            if (playWith < animal_num)
                play(list[playWith]);
            break;

        case 3:
            std::cout << "Whoes status do you want to see? :";
            std::cin >> playWith;
            if (playWith < animal_num)
                showStat(list[playWith]);
            break;
        }
        for (int i = 0; i != animal_num; i++)
        {
            passDay(list[i]);
        }
    }
    for (int i = 0; i != animal_num; i++)
        delete list[i];
}
