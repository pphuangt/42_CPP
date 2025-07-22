#include "PhoneBook.h"
#include <iostream>

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    while (std::cin.good()) {
        std::cout << "Enter command [ADD | SEARCH | EXIT]: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        if (input == "ADD")
            phonebook.add();
        else if (input == "SEARCH")
            phonebook.search();
        else if (input == "EXIT")
            break;
    }
    return 0;
}
