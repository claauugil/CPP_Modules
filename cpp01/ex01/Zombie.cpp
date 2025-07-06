/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:47:21 by claudia           #+#    #+#             */
/*   Updated: 2025/07/06 14:16:57 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{ 
    this->_name = name;
    std::cout << "\033[1;36m"
              << "Zombie " << this->_name << " created"
              << "\033[0m"
              << std::endl;
}

Zombie::Zombie(void)
{
    std::cout << "\033[1;36m"
    << "Zombie created"
    << "\033[0m"
    << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "\033[1;31m"
              << "Zombie " << this->_name << " destroyed"
              << "\033[0m"
              << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": "
              << "\033[1;33m"
              << "BraiiiiiiinnnzzzZ..."
              << "\033[0m"
              << std::endl;
}

void Zombie::setName (std::string name)
{
    this->_name = name;
}

