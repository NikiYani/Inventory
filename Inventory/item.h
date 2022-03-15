#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <list>
#include <modifier.h>
#include <memory>

enum ItemRarity{
    Common,
    Rare,
    Epic
};

enum ItemType{
    Clothes,
    Range,
    Melee
};

class Item
{
public:
    Item(const std::string& _ident,
         const ItemType& _type,
         const unsigned& _level,         
         const ItemRarity& _rarity):
        ident(_ident), type(_type), level(_level), rarity(_rarity){}

    virtual void Update(double value, TypeBuff buff) = 0;
    virtual void View();

    void addModif(std::shared_ptr<Modifier> modif);
    ItemType GetType(){return type;}
    int GetLevel(){return level;}
    ItemRarity GetRarity(){return rarity;}

private:
    const std::string ident;
    const ItemType type;
    const unsigned level;
    const ItemRarity rarity;
    std::list<std::shared_ptr<Modifier>> buffs;
};

#endif // ITEM_H
