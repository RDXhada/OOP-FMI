#include <iostream>

enum class Division
{
    UNKNOWN = -1, ASSASIN = 1, MEDIC = 2, MAGE = 3, TANK = 4
};

enum class Combat
{
    UNKNOWN = -1, RANGED = 1, MELEE = 2, BOTH = 3
};

struct Hero
{
    char *name;
    Division division;
    Combat combat;
};

void chooseDivision(Hero &hero)
{
    int division;
    std::cout << "Choose your division by numbers: " << std::endl;
    std::cout << "Assasin - 1, Medic - 2, Mage - 3, Tank - 4" << std::endl;
    std::cin >> division;
    
    switch (division)
    {
        case 1:
            hero.division = Division::ASSASIN;
            break;
        case 2:
            hero.division = Division::MEDIC;
            break;
        case 3:
            hero.division = Division::MAGE;
            break;
        case 4:
            hero.division = Division::TANK;
            break;
        default:
            break;
    }
}

void chooseCombat(Hero &hero)
{
    int combat;
    std::cout << "Choose your combat type by numbers: " << std::endl;
    std::cout << "Ranged - 1, Melee - 2, Both - 3" << std::endl;
    std::cin >> combat;
    
    switch (combat)
    {
        case 1:
            hero.combat = Combat::RANGED;
            break;
        case 2:
            hero.combat = Combat::MELEE;
            break;
        case 3:
            hero.combat = Combat::BOTH;
            break;
        default:
            break;
    }
}

void initHero(Hero &hero, const int nameLen)
{
    hero.name = new char[nameLen + 1];
    hero.name[nameLen] = '\0';
    
    for (int i = 0; i < nameLen; i++)
    {
        std::cin >> hero.name[i];
    }
    chooseDivision(hero);
    chooseCombat(hero);
}

void printDivision(const Hero &hero)
{
    switch (hero.division)
    {
        case Division::ASSASIN:
            std::cout << "Assasin\n";
            break;
        case Division::MEDIC :
            std::cout << "Mage\n";
            break;
        case Division::TANK :
            std::cout << "Tank\n";
            break;
        default:
            std::cout << "UNKNOWN\n";
            break;
    }
}

void printCombat(const Hero &hero)
{
    switch (hero.combat)
    {
        case Combat::RANGED:
            std::cout << "Ranged\n";
            break;
        case Combat::MELEE :
            std::cout << "Melee\n";
            break;
        case Combat::BOTH :
            std::cout << "BOTH\n";
            break;
        default:
            std::cout << "UNKNOWN\n";
            break;
    }
}

void printHeroStats(const Hero &hero)
{
    std::cout << "Hero names is: " << hero.name << std::endl;
    std::cout << "Division: "; printDivision(hero);
    std::cout << std::endl;
    std::cout << "Combat style: "; printCombat(hero);
}

int main()
{
    int heroNameLength;
    std::cout << "How long is the hero's name?\n";
    std::cin >> heroNameLength;
    
    Hero hero;
    initHero(hero, heroNameLength);
    printHeroStats(hero);
    
    delete[] hero.name;
    return 0;
}


