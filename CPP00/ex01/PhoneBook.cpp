#include "PhoneBook.h"

PhoneBook::PhoneBook(): index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
    std::string phoneNumber;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter nickname name: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);

    this->contacts[this->index].setFirstName(firstName);
    this->contacts[this->index].setLastName(lastName);
    this->contacts[this->index].setNickname(nickname);
    this->contacts[this->index].setDarkestSecret(darkestSecret);
    this->contacts[this->index].setPhoneNumber(phoneNumber);

    this->index = (this->index + 1) % 8;
}


void PhoneBook::search() {
    for (int i = 0; i < 8; i++)
    {
        Contact contact = this->contacts[i];

        if (contact.getFirstName().empty())
            break ;
        std::cout << std::setw(10) << std::right << (i + 1) << "|"
            << std::setw(10) << std::right 
            << _truncateField(contact.getFirstName(), 10) << "|"
            << std::setw(10) << std::right 
            << _truncateField(contact.getLastName(), 10) << "|"
            << std::setw(10) << std::right 
            << _truncateField(contact.getPhoneNumber(), 10) << std::endl;
    }

    int i;
    std::cout << "Enter index of the entry to display: ";
    if (!(std::cin >> i))
        std::cout << "Not a integer number" << std::endl;
    else if (i < 1 || i > 8 || this->contacts[i - 1].getFirstName().empty())
        std::cout << "Out of range" << std::endl;
    else
    {
        Contact contact = this->contacts[i - 1];
        std::cout << contact.getFirstName() << std::endl;
        std::cout << contact.getLastName() << std::endl;
        std::cout << contact.getNickname() << std::endl;
        std::cout << contact.getDarkestSecret() << std::endl;
        std::cout << contact.getPhoneNumber() << std::endl;
    }
    std::cin.clear();
    std::cin.ignore();
}

std::string PhoneBook::_truncateField(const std::string& str, size_t width) {
    if (str.length() > width)
        return str.substr(0, width - 1) + ".";
    return str;
}
