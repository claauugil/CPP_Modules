/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:36:13 by claudia           #+#    #+#             */
/*   Updated: 2025/07/06 19:10:17 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
    std::cout << "\033[1;32m" << "HumanA " << name << " created with ";
    std::cout << weapon.getType() <<  "\033[0m" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "\033[1;31m" << "HumanA " << this->_name << " destroyed" <<  "\033[0m" << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << \
        this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}