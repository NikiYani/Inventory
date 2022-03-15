#include "weapon.h"

void Weapon::Update(double value, TypeBuff buff)
{
    if(buff == TypeBuff::DamageBuff){
        AddDamage(value);
    }
    else if(buff == TypeBuff::SpeedBuff){
        AddSpeed(value);
    }
}

void Weapon::View()
{
    Item::View();

    std::cout << (char)204 << " " << "= Damage: " << damage << "\n";
    std::cout << (char)200 << " " << "= Speed: " << speed << "\n\n";
}
