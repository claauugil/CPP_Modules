/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:47:21 by claudia           #+#    #+#             */
/*   Updated: 2025/07/02 19:02:52 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{ 
    this->_name = name;
    std::cout << "Zombie " << this->_name << " created" << std:: endl;
}

Zombie::~Zombie (void)
{
    std::cout << "Zombie " << this->_name << " destroyed" << std:: endl;
}

void Zombie::announce()
{
    std::cout << this->_name << "BraiiiiiiinnnzzzZ..." << std::endl;
}