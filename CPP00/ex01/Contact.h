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
    Contact(const Contact& other);
    Contact& operator=(const Contact& other);
    ~Contact();

    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getDarkestSecret(void);
    std::string getPhoneNumber(void);
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickname);
    void setDarkestSecret(const std::string &darkestSecret);
    void setPhoneNumber(const std::string &phoneNumber);
};

#endif
