#ifndef MODIFIER_H
#define MODIFIER_H

#include <string>
#include <vector>

enum TypeBuff{
    DamageBuff,
    SpeedBuff,
    ProtectionBuff
};

class Modifier
{
public:
    Modifier(const std::string& _ident,
             const std::vector<std::vector<std::string>>& _filters,
             const TypeBuff& _type,
             const double& _value):
        ident(_ident), filters(_filters), type(_type), value(_value){}

    std::vector<std::vector<std::string>> GetCond(){return filters;}
    TypeBuff GetTypeBuff(){return type;}
    double GetValue(){return value;}

private:
    const std::string ident;
    const std::vector<std::vector<std::string>> filters;
    const TypeBuff type;
    const double value;
};

#endif // MODIFIER_H
