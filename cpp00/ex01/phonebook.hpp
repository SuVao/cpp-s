#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <iomanip>

#define MAX_CONTACTS 9


class Contact {
    private:
public:
    // construtor
    int index;
    std::string lName;
    std::string fName;
    std::string Darkest;
    std::string PhoneNumber;
    std::string Nickname;
    Contact();
    //~Contact();
    Contact(int index, std::string lName, std::string fName, std::string Darkest, std::string PhoneNumber, std::string Nickname);
    void    display_info() const;
   // void    menu_choice(const std::string &comand);
};

class Phonebook {
    private:
    std::vector<Contact> contacts;
    public:
    void menu_choice(const std::string &comand);
    Contact add_contact(int index, std::string lName, std::string fName, std::string Darkest, std::string PhoneNumber, std::string Nickname);
    //PhoneBook() : index(0) {}
    void display_contacts();
};

#endif
