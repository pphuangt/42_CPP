#include "PhoneBook.h"

PhoneBook::PhoneBook(): index(0) {}

PhoneBook::PhoneBook(const PhoneBook& other): index(other.index)
{
    for (int i = 0; i < 8; i++) { contacts[i] = other.contacts[i]; }
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
    if (this != &other) {
        index = other.index;
        for (int i = 0; i < 8; i++) { contacts[i] = other.contacts[i]; }
    }
    return *this;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
    std::string phoneNumber;

    if (!_getInput("Enter first name: ", firstName)) return;
    if (!_getInput("Enter last name: ", lastName)) return;
    if (!_getInput("Enter nickname: ", nickname)) return;
    if (!_getInput("Enter darkest secret: ", darkestSecret)) return;
    if (!_getInput("Enter phone number: ", phoneNumber)) return;

    this->contacts[this->index].setFirstName(firstName);
    this->contacts[this->index].setLastName(lastName);
    this->contacts[this->index].setNickname(nickname);
    this->contacts[this->index].setDarkestSecret(darkestSecret);
    this->contacts[this->index].setPhoneNumber(phoneNumber);

    this->index = (this->index + 1) % 8;
}

void PhoneBook::search()
{
    int i = 0;

    this->_display();
    std::cout << "Enter index of the entry to display: ";
    if (!(std::cin >> i)) {
        if (!std::cin.eof()) std::cout << "Not an integer number" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (i < 1 || i > 8 || this->contacts[i - 1].getFirstName().empty())
        std::cout << "Out of range" << std::endl;
    else {
        Contact contact = this->contacts[i - 1];
        std::cout << "first name: " << contact.getFirstName() << std::endl;
        std::cout << "last name: " << contact.getLastName() << std::endl;
        std::cout << "nickname: " << contact.getNickname() << std::endl;
        std::cout << "darkest secret: " << contact.getDarkestSecret()
                  << std::endl;
        std::cout << "phone number: " << contact.getPhoneNumber() << std::endl;
    }
}

std::string PhoneBook::_truncateField(const std::string& str)
{
    if (str.length() > 10) return str.substr(0, 9) + ".";
    return str;
}

bool PhoneBook::_getInput(const std::string& prompt, std::string& input)
{
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        if (!input.empty()) return true;
    }
}

void PhoneBook::_display() const
{
    for (int i = 0; i < 8; i++) {
        Contact contact = this->contacts[i];

        if (contact.getFirstName().empty()) break;
        std::cout << std::setw(10) << std::right << (i + 1) << "|"
                  << std::setw(10) << std::right
                  << _truncateField(contact.getFirstName()) << "|"
                  << std::setw(10) << std::right
                  << _truncateField(contact.getLastName()) << "|"
                  << std::setw(10) << std::right
                  << _truncateField(contact.getPhoneNumber()) << std::endl;
    }
}
