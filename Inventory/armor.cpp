#include "armor.h"

void Armor::View()
{
    Item::View();

    std::cout << (char)200 << " " << "= Protection: " << protection << "\n\n";
}
