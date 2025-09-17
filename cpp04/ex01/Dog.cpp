/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:58:56 by claudia           #+#    #+#             */
/*   Updated: 2025/08/28 12:31:42 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal ("Dog")
{
    this->_brain = new Brain();
    std::cout << GREEN << "[Dog] default constructor called. Type: " << _type << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->_brain = new Brain(*copy._brain); // deep copy
    std::cout << GREEN << "[Dog] copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    std::cout << GREEN <<"Dog copy assignment operator called" << RESET << std::endl;
    return (*this);
}

Dog::~Dog(void)
{
    delete this->_brain;
    std::cout << RED << "Dog has been destroyed" << RESET <<std::endl;
}

Brain &Dog::getBrain(void) const
{
    return (*this->_brain);
}

void Dog::makeSound(void) const
{
    std::cout << YELLOW << "The dog says: woof woof woof" << RESET << std::endl;
}
