#ifndef CONTACT_H
#define CONTACT_H
# include <string>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _darkestSecret;
    std::string _phoneNumber;

public:
    Contact();
    ~Contact();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getDarkestSecret();
    std::string getPhoneNumber();
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickname);
    void setDarkestSecret(const std::string &darkestSecret);
    void setPhoneNumber(const std::string &phoneNumber);
};

#endif
