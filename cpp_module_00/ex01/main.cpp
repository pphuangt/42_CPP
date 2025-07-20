#include "PhoneBook.h"
#include <iostream>

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    while (input != "EXIT") {
        std::cout << "Enter command [ADD | SEARCH | EXIT]: ";
        std::getline(std::cin, input);
        if (!std::cin.good()) break;
        if (input == "ADD") phonebook.add();
        else if (input == "SEARCH") phonebook.search();
    }
    return 0;
}