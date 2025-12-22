#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
private:
    Contact contacts[8];
    int contactCount;
    int nextIndex;
public:
    PhoneBook();
    void addContact(const Contact& contact);
    void listContacts() const;
    void showContact(int index) const;
    int getContactCount() const;
};

#endif