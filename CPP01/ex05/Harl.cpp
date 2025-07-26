#include "Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(const std::string& level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*complaints[4])(void) = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*complaints[i])();
            return;
        }
    }
}

void Harl::_debug()
{
    std::cout << "[DEBUG] I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger. "
                 "I really do!" << std::endl;
}

void Harl::_info()
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. "
                 "You didn't put enough bacon in my burger! If you did, I "
                 "wouldn't be asking for more!" << std::endl;
}

void Harl::_warning()
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. "
                 "I've been coming for years whereas you started working here "
                 "since last month." << std::endl;
}

void Harl::_error()
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now."
              << std::endl;
}