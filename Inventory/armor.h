#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor : public Item
{
public:
    Armor(const std::string& _ident,
          const ItemType& _type,
          const unsigned& _level,
          const ItemRarity& _rarity,
          const double& _protection):
        Item(_ident, _type, _level, _rarity), protection(_protection){}

    void View();
    void AddProtection(double _protection){protection += _protection;}
    void Update(double value, TypeBuff buff){AddProtection(value);}

private:
    double protection;
};

#endif // ARMOR_H
