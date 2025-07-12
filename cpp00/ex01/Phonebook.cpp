/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:07:07 by claudia           #+#    #+#             */
/*   Updated: 2025/07/02 15:53:58 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Phonebook_utils.hpp"

Phonebook::Phonebook(void)
{
    this->_index = 0;
}

Phonebook::~Phonebook(void)
{
}

bool checkIsAlpha(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isalpha(str[i]))
            return false ;
    }
    return true ;
}

bool checkIsNumeric(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std:: isdigit(str[i]))
            return false ;
    }
    return true ;
}

void Phonebook::add(void)
{
    std::string     str;
    
    Contact temp;
    str = "";
    if (this->_index > 7)
        std::cout << "WARNING: This information will be overwitten: " 
                << this->_contacts[this->_index % 8].get_fst_name() << std::endl;
    while (true)
    {
        std::cout << "\033[1;32mEnter a first name:\033[0m ";
        if (!std::getline(std::cin, str) || str.empty() || !checkIsAlpha(str))
        {
            if (std::cin.eof()) return;
                std::cout << "The last name can't be empty and must be alphabetic. \n";
                continue;
        }
        temp.set_fst_name(str);
        break;
    }
    while (true)
    {
        std::cout << "\033[1;32mEnter a last name:\033[0m ";
        if (!std::getline(std::cin, str) || str.empty() || !checkIsAlpha(str))
        {
            if (std::cin.eof()) return;
                std::cout << "The last name can't be empty and must be alphabetic. \n";
                continue;
        }
        temp.set_lname(str);
        break;
    }
    while (true)
    {
        std::cout << "\033[1;32mEnter a nickname:\033[0m ";
        if (!std::getline(std::cin, str) || str.empty() || !checkIsAlpha(str))
        {
            if (std::cin.eof()) return;
                std::cout << "The last nickname can't be empty and must be alphabetic. \n";
                continue;
        }
        temp.set_nickname(str);
        break;
    }
    while (true)
    {
        std::cout << "\033[1;32mEnter a phone number:\033[0m ";
        if (!std::getline(std::cin, str) || str.empty() || !checkIsNumeric(str))
        {
            if (std::cin.eof()) return;
                std::cout << "The phone number can't be empty and must be numeric.\n \n";
                continue;
        }
        temp.set_phone_num(str);
        break;
    }
    while (true)
    {
        std::cout << "\033[1;32mEnter the darkest secret:\033[0m ";
        if (!std::getline(std::cin, str) || str.empty() || !checkIsAlpha(str))
        {
            if (std::cin.eof()) return;
                std::cout << "The last name can't be empty and must be alphabetic. \n";
                continue;
        }
        temp.set_secret(str);
        break;
    }
    this->_contacts[this->_index % 8] = temp;
    std::cout << temp.get_fst_name() << " added contact to phonebook ["
        << (this->_index % 8 + 1) << "/8]" << std::endl;
    this->_index++;
}

Contact Phonebook::get_contact(int index)
{
    return (this->_contacts[index % 8]); 
}

void Phonebook:: search(void)
{
    std::string str;

    if (!show_table(this->_contacts))
    {
        std::cout << std::endl << "The phonebook is empty" << std::endl;
        return ;
    }
    while (!std::cin.eof())
    {
        std::cout << "Select an index: ";
        if (std::getline(std::cin, str) && str != "")
        {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
                        this->_contacts[str[0] - 1 - '0'].get_fst_name().size())
                break;
        }
        if (str != "")
            std::cout << "Invalid index!" << std::endl;
    }
    if (!std::cin.eof())
        this->print(this->_contacts[str[0] - 1 - '0']);
}

void Phonebook::print(Contact contact)
{
    if (!contact.get_fst_name().size())
    {
        std::cout << "Failed to get information about this contact";
        return;
    }
    std::cout << "\033[1;32mFirst Name: \033[0m" << contact.get_fst_name() << std::endl;
    std::cout << "\033[1;32mLast Name: \033[0m" << contact.get_lst_name() << std::endl;
    std::cout << "\033[1;32mNickname: \033[0m" << contact.get_nickname() << std::endl;
    std::cout << "\033[1;32mPhone Number: \033[0m" << contact.get_phone_num() << std::endl;
    std::cout << "\033[1;32mDarkest Secret: \033[0m" << contact.get_secret() << std::endl;
}
