#include "Harl.h"

int main()
{
    Harl harl;

    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Testing INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Testing WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Testing ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    return 0;
}