/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:58:56 by claudia           #+#    #+#             */
/*   Updated: 2025/08/28 10:31:22 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal ("Cat")
{
    std::cout << BLUE << "[Cat] default constructor called. Type: " << _type << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << BLUE << "[Cat] copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
    }
    std::cout << BLUE <<"[Cat] copy assignment operator called" << RESET << std::endl;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << RED << "[Cat] has been destroyed" << RESET <<std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << YELLOW << "The cat says: meow meow meow." << RESET << std::endl;
}