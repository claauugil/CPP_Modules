/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:46:02 by claudia           #+#    #+#             */
/*   Updated: 2025/08/16 15:18:59 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("(undefined)")
{
    std::cout << CYAN << "[WrongAnimal] constructed with default constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type): _type(type)
{
    std::cout << CYAN << "[WrongAnimal] " << this->_type << " has been constructed" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << CYAN <<"WrongAnimal copy constructor called" << RESET <<std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
    {
        _type = copy._type;
    }
    std::cout << CYAN <<"[WrongAnimal] copy assignment operator called" << RESET <<std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << RED << "A WrongAnimal of type: " << _type << " has been destroyed" << RESET << std::endl;
}

std::string const &WrongAnimal::getType(void) const
{
    return (this->_type);
}

void WrongAnimal::setType(const std::string &type)
{
    this->_type =  type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "A wrong animal has made a sound" << std::endl;
}