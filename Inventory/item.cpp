#include "item.h"

void Item::View()
{
    std::string ItemTypeStr[]{"Clothes", "Range", "Melee"};
    std::string ItemRarityStr[]{"Common", "Rare", "Epic"};

    std::cout << (char)201 << " " << ident << "\n";
    std::cout << (char)204 << " " << "= ItemType: " << ItemTypeStr[type] << "\n";
    std::cout << (char)204 << " " << "= Level: " << level << "\n";
    std::cout << (char)204 << " " << "= ItemRarity: " << ItemRarityStr[rarity] << "\n";
}

void Item::addModif(std::shared_ptr<Modifier> modif)
{
    buffs.push_back(modif);
}
