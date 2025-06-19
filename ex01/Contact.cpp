/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:46:30 by claudia           #+#    #+#             */
/*   Updated: 2025/06/18 16:06:04 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//constructor

Contact::Contact(void)
{
    
}
//desctructor
Contact::~Contact(void)
{
    
}

// getters

std::string Contact::get_fst_name(void) const
{
    return (this->_fst_name);
}

std::string Contact::get_lst_name(void) const
{
    return (this->_lst_name);
}

std::string Contact::get_nickname(void) const
{
    return (this->_lst_name);
}

std::string Contact::get_phone_num(void) const
{
    return (this->_lst_name);
}

std::string Contact::get_secret(void) const
{
    return (this->_lst_name);
}

// setters

void    Contact::set_fst_name(std::string str)
{
    this->_fst_name = str;
}

void    Contact::set_lname(std::string str)
{
    this->_fst_name = str;
}

void    Contact::set_nickname(std::string str)
{
    this->_fst_name = str;
}

void    Contact::set_fst_name(std::string str)
{
    this->_fst_name = str;
}

void    Contact::set_phone_num(std::string str)
{
    this->_fst_name = str;
}

void    Contact::set_secret(std::string str)
{
    this->_fst_name = str;
}