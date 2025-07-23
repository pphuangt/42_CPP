#include "PhoneBook.h"

PhoneBook::PhoneBook(): _index(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::add()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
    std::string phoneNumber;

    if (!_readInput("Enter first name: ", firstName)) return false;
    if (!_readInput("Enter last name: ", lastName)) return false;
    if (!_readInput("Enter nickname: ", nickname)) return false;
    if (!_readInput("Enter darkest secret: ", darkestSecret)) return false;
    if (!_readInput("Enter phone number: ", phoneNumber)) return false;
    _contacts[_index].setFirstName(firstName);
    _contacts[_index].setLastName(lastName);
    _contacts[_index].setNickname(nickname);
    _contacts[_index].setDarkestSecret(darkestSecret);
    _contacts[_index].setPhoneNumber(phoneNumber);
    _index = (_index + 1) % 8;
    return true;
}

bool PhoneBook::search()
{
    std::string s;

    _displayList();
    if (!_readInput("Enter index: ", s)) return false;
    if (s == "1")
        _displayContact(0);
    else if (s == "2")
        _displayContact(1);
    else if (s == "3")
        _displayContact(2);
    else if (s == "4")
        _displayContact(3);
    else if (s == "5")
        _displayContact(4);
    else if (s == "6")
        _displayContact(5);
    else if (s == "7")
        _displayContact(6);
    else if (s == "8")
        _displayContact(7);
    return true;
}

bool PhoneBook::_readInput(const std::string& prompt, std::string& s)
{
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, s)) return false;
        s = _trim(s);
        if (!s.empty()) return true;
    }
}

void PhoneBook::_displayList()
{
    std::cout << std::setw(10) << std::right << "index" << "|"
    << std::setw(10) << std::right << "first name" << "|"
    << std::setw(10) << std::right << "last name" << "|"
    << std::setw(10) << std::right << "nickname" << std::endl;
    for (int i = 0; i < 8; i++) {
        if (_contacts[i].getFirstName().empty()) break;
        std::cout << std::setw(10) << std::right << (i + 1) << "|"
                  << std::setw(10) << std::right
                  << _truncateField(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << std::right
                  << _truncateField(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << std::right
                  << _truncateField(_contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::_displayContact(int index)
{
    std::cout << "first name: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "last name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "nickname: " << _contacts[index].getNickname() << std::endl;
    std::cout << "darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
    std::cout << "phone number: " << _contacts[index].getPhoneNumber() << std::endl;
}


std::string PhoneBook::_trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    size_t end = s.find_last_not_of(" \t\n\r\f\v");

    if (start >= s.length()) return "";
    return s.substr(start, end - start + 1);
}

std::string PhoneBook::_truncateField(const std::string& s)
{
    if (s.length() > 10) return s.substr(0, 9) + ".";
    return s;
}
