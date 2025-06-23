/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:07:07 by claudia           #+#    #+#             */
/*   Updated: 2025/06/23 17:49:49 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
// #include "Phonebook_utils.hpp"

Phonebook::Phonebook(void)
{
    this->_index = 0;
}

Phonebook::~Phonebook(void)
{
}

void Phonebook::add(void)
{
    std::string     str;
    
    str = "";
    if (this->_index > 7)
        std::cout << "WARNING: This information will be overwitten: " << this->_contacts[this->_index % 8].get_fst_name() << std::endl;
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter a first name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contacts[this->_index % 8].set_fst_name(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter a last name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contacts[this->_index % 8].set_lname(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter a nick name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contacts[this->_index % 8].set_nickname(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter your phone number: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contacts[this->_index % 8].set_phone_num(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter " << this->_contacts[this->_index % 8].get_fst_name() << "'s darkest secret: ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->_contacts[this->_index % 8].set_secret(str);
            std::cout << this->_contacts[this->_index % 8].get_fst_name() << \
                    " added contact to phonebook [" << this->_index % 8 + 1 << "/8]" << std::endl;
        }
    }
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
    std::cout <<std::endl << "Asking contact information..." << std::endl;
    if (!contact.get_fst_name().size())
    {
        std::cout << "Failed to get information about this contact";
        return ;
    }
    std::cout << "First Name: " << contact.get_fst_name() << std::endl;
    std::cout << "Last Name: " << contact.get_lst_name() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone Number: " << contact.get_phone_num() << std::endl;
    std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}