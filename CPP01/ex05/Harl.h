#ifndef HARL_H
#define HARL_H
#include <iostream>
#include <string>

class Harl {
private:
    void _debug();
    void _info();
    void _warning();
    void _error();

public:
    Harl();
    ~Harl();
    void complain(const std::string& level);
};

#endif
