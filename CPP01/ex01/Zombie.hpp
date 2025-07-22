#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    ~Zombie();
    void setName(const std::string& name);
    void announce(void) const;
};

#endif