/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:07:07 by claudia           #+#    #+#             */
/*   Updated: 2025/06/18 18:39:44 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
// #include "Phonebook_utils.hpp"

Phonebook::Phonebook(void)
{
}

Phonebook::~Phonebook(void)
{
}

void Phonebook::add(void)
{
    std::string     str;
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter a first name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contacts[this->_index % 8].set_fst_name(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter a first name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contacts[this->_index % 8].set_lname(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter a first name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contacts[this->_index % 8].set_nickname(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter a first name: ";
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
            std::cout << this->_contacts[this->_index % 8].get_secret() << \ << std::endl;
                " succesfully added to phonebook[" << this->_index % 8 + 1 << /8"]"
        }
    }
    
}