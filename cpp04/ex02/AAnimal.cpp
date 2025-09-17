/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:20:14 by cgil              #+#    #+#             */
/*   Updated: 2025/09/01 13:06:38 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("(undefined)")
{
    std::cout << CYAN << "[Animal] constructed with default constructor" << RESET << std::endl;
}

AAnimal::AAnimal(std::string const &type): _type(type)
{
    std::cout << CYAN << "[Animal] " << this->_type << " has been constructed" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;
    std::cout << CYAN <<"Animal copy constructor called" << RESET <<std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    if (this != &copy)
    {
        _type = copy.getType();
    }
    std::cout << CYAN <<"[Animal] copy assignment operator called" << RESET <<std::endl;
    return (*this);
}

AAnimal::~AAnimal(void)
{
    std::cout << RED << "An Animal of type: " << _type << " has been destroyed" << RESET << std::endl;
}

std::string const &AAnimal::getType(void) const
{
    return (this->_type);
}

void AAnimal::setType(const std::string &type)
{
    this->_type =  type;
}