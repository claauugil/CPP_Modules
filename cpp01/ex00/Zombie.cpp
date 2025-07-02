/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:47:21 by claudia           #+#    #+#             */
/*   Updated: 2025/07/02 19:34:06 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{ 
    this->_name = name;
    std::cout << "\033[1;36m"  // Azul claro (cyan intenso)
              << "Zombie " << this->_name << " created"
              << "\033[0m"     // Reset color
              << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "\033[1;31m"  // Rojo intenso
              << "Zombie " << this->_name << " destroyed"
              << "\033[0m"     // Reset color
              << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": "
              << "\033[1;33m"      // Amarillo brillante
              << "BraiiiiiiinnnzzzZ..."
              << "\033[0m"         // Reset color
              << std::endl;
}
