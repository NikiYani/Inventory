#include <QCoreApplication>
#include <memory>
#include <list>

#include <armor.h>
#include <modifier.h>
#include <weapon.h>

void AddingModifiers(std::vector<std::unique_ptr<Item>>& inventory,
                     const std::vector<std::shared_ptr<Modifier>>& listBuffs)
{
    for(unsigned i = 0; i < inventory.size(); ++i){
        for(unsigned j = 0; j < listBuffs.size(); ++j){
            // Проверка условий модификатор
            bool checkSatisfies = false;
            size_t iterSatisfies = 0;
            while(iterSatisfies != listBuffs[j]->GetCond().size()){
                if(listBuffs[j]->GetCond()[iterSatisfies][0] == "level"){
                    if(listBuffs[j]->GetCond()[iterSatisfies][1] == ">"){
                        if(inventory[i]->GetLevel() > std::atoi(listBuffs[j]->GetCond()[iterSatisfies][2].c_str())){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == ">="){
                        if(inventory[i]->GetLevel() >= std::atoi(listBuffs[j]->GetCond()[iterSatisfies][2].c_str())){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == "<="){
                        if(inventory[i]->GetLevel() <= std::atoi(listBuffs[j]->GetCond()[iterSatisfies][2].c_str())){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == "<"){
                        if(inventory[i]->GetLevel() < std::atoi(listBuffs[j]->GetCond()[iterSatisfies][2].c_str())){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == "=="){
                        if(inventory[i]->GetLevel() == std::atoi(listBuffs[j]->GetCond()[iterSatisfies][2].c_str())){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                }
                else if(listBuffs[j]->GetCond()[iterSatisfies][0] == "rarity"){
                    if(listBuffs[j]->GetCond()[iterSatisfies][1] == "Common"){
                        if(inventory[i]->GetRarity() == ItemRarity::Common){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == "Rare"){
                        if(inventory[i]->GetRarity() == ItemRarity::Rare){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == "Epic"){
                        if(inventory[i]->GetRarity() == ItemRarity::Epic){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                }
                else if(listBuffs[j]->GetCond()[iterSatisfies][0] == "type"){
                    if(listBuffs[j]->GetCond()[iterSatisfies][1] == "Clothes"){
                        if(inventory[i]->GetType() == ItemType::Clothes){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == "Melee"){
                        if(inventory[i]->GetType() ==  ItemType::Melee){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                    else if(listBuffs[j]->GetCond()[iterSatisfies][1] == "Range"){
                        if(inventory[i]->GetType() ==  ItemType::Range){
                            checkSatisfies = true;
                        }
                        else{
                            checkSatisfies = false;
                        }
                    }
                }

                if(checkSatisfies){
                    inventory[i]->addModif(listBuffs[j]);

                    // Изменение характеристик предмета
                    inventory[i]->Update(listBuffs[j]->GetValue(), listBuffs[j]->GetTypeBuff());
                    break;
                }

                ++iterSatisfies;
            }
        }
    }
}

void ConsoleOutput(std::vector<std::unique_ptr<Item>>& inventory)
{
    std::cout << "=====================" << "MY_INVENTORY" << "=====================" << "\n\n";

    for(unsigned i = 0; i < inventory.size(); ++i){
        inventory[i]->View();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создания списка указателей на модификаторы
    std::vector<std::shared_ptr<Modifier>> listBuffs;

    // Заполнение вектора
    std::vector<std::vector<std::string>> v = {{"level", ">=", "4"}, {"type", "Range"}};
    listBuffs.push_back(std::make_shared<Modifier>("eagle_eye", v, TypeBuff::DamageBuff, 10));

    v.clear();
    v = {{"rarity", "Rare"}};
    listBuffs.push_back(std::make_shared<Modifier>("donatium_steel", v, TypeBuff::ProtectionBuff, 15));

    v.clear();
    v = {{"type", "Melee"}, {"type", "Range"}};
    listBuffs.push_back(std::make_shared<Modifier>("rage_drink", v, TypeBuff::SpeedBuff, 0.4));

    v.clear();

    // Создание вектора указателей на предметы в инвентаре
    std::vector<std::unique_ptr<Item>> inventory;

    inventory.push_back(std::make_unique<Weapon>("axe_01", ItemType::Melee, 3, ItemRarity::Rare, 12, 0.9));
    inventory.push_back(std::make_unique<Weapon>("revolver_01", ItemType::Range, 5, ItemRarity::Common, 42, 2));
    inventory.push_back(std::make_unique<Weapon>("revolver_02", ItemType::Range, 3, ItemRarity::Rare, 50, 2.1));
    inventory.push_back(std::make_unique<Weapon>("machinegun_01", ItemType::Range, 5, ItemRarity::Epic, 83.1, 10));
    inventory.push_back(std::make_unique<Armor>("jacket_01", ItemType::Clothes, 2, ItemRarity::Common, 2));
    inventory.push_back(std::make_unique<Armor>("bulletprof_vest_01", ItemType::Clothes, 5, ItemRarity::Rare, 30));

    // Добавление модификаторов к предметам
    AddingModifiers(inventory, listBuffs);

    // Вывод в консоль
    ConsoleOutput(inventory);


    return a.exec();
}
