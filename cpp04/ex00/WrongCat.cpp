/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:43:41 by claudia           #+#    #+#             */
/*   Updated: 2025/08/28 10:33:49 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal ("WrongCat")
{
    std::cout << BLUE << "[WrongCat] default constructor called. Type: " << _type << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << BLUE << "[WrongCat] copy constructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
    {
        WrongAnimal::operator=(copy);
    }
    std::cout << BLUE <<"[WrongCat] copy assignment operator called" << RESET << std::endl;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << RED << "[WrongCat] has been destroyed" << RESET <<std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << YELLOW << "The wrong cat says: meow meow meow" << RESET << std::endl;
}