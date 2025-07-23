#include "PhoneBook.h"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string s;

    while (true) {
        std::cout << "Enter command [ADD, SEARCH, EXIT]: ";
        if (!std::getline(std::cin, s)) break;
        if (s == "ADD") {
            if (!phonebook.add())
                break;
        }
        else if (s == "SEARCH") {
            if (!phonebook.search())
                break;
        }
        else if (s == "EXIT")
            break;
    }
    return 0;
}
