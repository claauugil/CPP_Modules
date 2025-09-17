/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:20:14 by cgil              #+#    #+#             */
/*   Updated: 2025/08/28 11:06:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("(undefined)")
{
    std::cout << CYAN << "[Animal] constructed with default constructor" << RESET << std::endl;
}

Animal::Animal(std::string const &type): _type(type)
{
    std::cout << CYAN << "[Animal] " << this->_type << " has been constructed" << RESET << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << CYAN <<"Animal copy constructor called" << RESET <<std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
    {
        _type = copy.getType();
    }
    std::cout << CYAN <<"[Animal] copy assignment operator called" << RESET <<std::endl;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << RED << "An Animal of type: " << _type << " has been destroyed" << RESET << std::endl;
}

std::string const &Animal::getType(void) const
{
    return (this->_type);
}

void Animal::setType(const std::string &type)
{
    this->_type =  type;
}

void Animal::makeSound(void) const
{
    std::cout << "An animal has made a sound" << std::endl;
}