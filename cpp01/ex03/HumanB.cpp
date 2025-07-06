/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:41:47 by aperez-b          #+#    #+#             */
/*   Updated: 2025/07/06 19:06:49 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
	this->_name = name;
	std::cout <<  "\033[1;32m"  << "HumanB " << name << " created with no weapon" << "\033[0m" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "\033[1;31m" << "HumanB " << this->_name << " destroyed" << "\033[0m" << std::endl;
}

void	HumanB::attack(void)
{
	
	std::cout << this->_name << " attacks with his " << \
		this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}