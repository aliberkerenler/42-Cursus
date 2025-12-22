#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

void promptField(const std::string& field, std::string& value)
{
    std::cout << field << ": ";
    if(!std::getline(std::cin, value))
		{
			std::cout << "EOF (CTRL + D) Received." << std::endl;
			std::cout << "Bye!" << std::endl;
			exit(0);
		}
    while (value.empty())
	{
        std::cout << "Cannot be empty!" << std::endl;
        std::cout << field << ": ";
        std::getline(std::cin, value);
    }
}

bool isValidPhoneNumber(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return !str.empty();
}

int main()
{
    PhoneBook pb;
    std::string command;
    while (true)
	{
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, command))
		{
			std::cout << "EOF (CTRL + D) Received." << std::endl;
			break;
		}
        if (command == "EXIT")
            break;
        else if (command == "ADD")
		{
            Contact c;
			std::string value;
			promptField("First Name", value); c.setFirstName(value);
			promptField("Last Name", value); c.setLastName(value);
			promptField("Nickname", value); c.setNickname(value);
			promptField("Phone Number", value);
			while (!isValidPhoneNumber(value))
			{
    			std::cout << "Phone number must contain only digits!" << std::endl;
    			promptField("Phone Number", value);
			}
			c.setPhoneNumber(value);
			promptField("Darkest Secret", value); c.setDarkestSecret(value);
			pb.addContact(c);
            std::cout << "Contact added!" << std::endl;
        }
        else if (command == "SEARCH")
		{
            pb.listContacts();
		    std::cout << "Enter index to display: ";
    		std::getline(std::cin, command);

		    bool is_valid = !command.empty();
		    for (size_t i = 0; i < command.size(); i++)
		    {
    	    	if (command[i] < '0' || command[i] > '9')
        		{
        		    is_valid = false;
        		    break;
        		}
    		}
		    if (is_valid)
		    {
        		std::stringstream ss(command);
        		int index;
        		ss >> index;
        		pb.showContact(index);
			}
    		else
    		{
        		std::cout << "Invalid input." << std::endl;
    		}
        }
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}