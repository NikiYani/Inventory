#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item
{
public:
    Weapon(const std::string& _ident,
           const ItemType& _type,
           const unsigned& _level,
           const ItemRarity& _rarity,
           const double& _damage,
           const double& _speed):
        Item(_ident, _type, _level, _rarity), damage(_damage), speed(_speed){}

    void View();
    void AddDamage(double _damage){damage += _damage;}
    void AddSpeed(double _speed){speed += _speed;}
    void Update(double value, TypeBuff buff);

private:
    double damage;
    double speed;
};

#endif // WEAPON_H
