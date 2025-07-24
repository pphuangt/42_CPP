#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon(const std::string& type);
    ~Weapon();
    std::string& getType();
    void setType(const std::string& type);
};

#endif
