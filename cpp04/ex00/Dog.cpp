/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:58:56 by claudia           #+#    #+#             */
/*   Updated: 2025/08/28 10:31:42 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal ("Dog")
{
    std::cout << GREEN << "[Dog] default constructor called. Type: " << _type << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << GREEN << "[Dog] copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
    }
    std::cout << GREEN <<"Dog copy assignment operator called" << RESET << std::endl;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << RED << "Dog has been destroyed" << RESET <<std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << YELLOW << "The dog says: woof woof woof." << RESET << std::endl;
}