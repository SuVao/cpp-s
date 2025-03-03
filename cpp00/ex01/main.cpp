
#include "phonebook.hpp"

void    Contact::display_info() const
{
    std::cout << index << "     | " << fName << " | " << lName << " | " << Nickname << std::endl;
}

std::string    define_size(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    else if (str.length() < 10)
        str.append(10 - str.length(), ' ');
    return (str);
}

void Phonebook::display_contacts() {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
            return;
        }
        //std::cout << std::setw(10) << "Index" << " | "
        //          << std::setw(10) << "First Name" << " | "
        //          << std::setw(10) << "Last Name" << " | "
        //          << std::setw(10) << "Nickname" << std::endl;
        std::cout << "Index | First Name | Last Name  | Nickname " << std::endl;

        for (const auto &contact : contacts) {
            contact.display_info();
        }
    }

void Phonebook::menu_choice(const std::string &comand) {
    static int i = 0;

    if (comand == "ADD") {
        std::string fName, lName, darkest, Nickname, PhoneNumber;

        std::cout << "Add New Contact:" << std::endl;
        std::cout << "Write the first name:" << std::endl;
        std::cin >> fName;
        std::cout << "Write the last name:" << std::endl;
        std::cin >> lName;
        std::cout << "Write the Nickname:" << std::endl;
        std::cin >> Nickname;
        std::cout << "Write the darkest secret:" << std::endl;
        std::cin >> darkest;
        std::cout << "Write the Phone number:" << std::endl;
        std::cin >> PhoneNumber;

        // Criar novo contato e exibir
        Contact new_contact(i, define_size(lName), define_size(fName),
                            define_size(darkest), define_size(PhoneNumber), define_size(Nickname));
        if (contacts.size() < MAX_CONTACTS)
            contacts.push_back(new_contact);
        else
            contacts[i % MAX_CONTACTS] = new_contact;

        //new_contact.display_info();

        i++; // Incrementa o índice
    }
    if (comand == "SEARCH")
    {
        display_contacts();
    }
    else
        return ;
}

//Contact::Contact(int index, std::string lName, std::string fName, std::string Darkest, std::string PhoneNumber, std::string Nickname){}

Contact::Contact(int idx, std::string lname, std::string fname,
                 std::string darkest, std::string phone, std::string nickname)
    : index(idx), lName(lname), fName(fname), Darkest(darkest),
      PhoneNumber(phone), Nickname(nickname) {}


Contact::Contact() {}

int main()
{
    Phonebook my_phonebook;
    std::string prompt;
    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> prompt;
        //if (!(std::cin >> prompt))
        //    break ;
        if (prompt == "EXIT")
            break ;
        my_phonebook.menu_choice(prompt);
        std::cout << "my prompt: " << prompt << std::endl;
    }
}
