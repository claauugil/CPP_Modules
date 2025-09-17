/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:58:56 by claudia           #+#    #+#             */
/*   Updated: 2025/08/28 12:29:57 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal ("Cat")
{
    this->_brain = new Brain();
    std::cout << BLUE << "[Cat] default constructor called. Type: " << _type << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->_brain = new Brain(*copy._brain);
    std::cout << BLUE << "[Cat] copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    std::cout << BLUE <<"[Cat] copy assignment operator called" << RESET << std::endl;
    return (*this);
}

Cat::~Cat(void)
{
    delete this->_brain;
    std::cout << RED << "[Cat] has been destroyed" << RESET <<std::endl;
}
// returns reference to brain
Brain &Cat::getBrain(void) const
{
    return (*this->_brain);
}

void Cat::makeSound(void) const
{
    std::cout << YELLOW << "The cat says: meow meow meow" << RESET << std::endl;
}