/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:35:49 by claudia           #+#    #+#             */
/*   Updated: 2025/08/13 15:57:24 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("(default_clap_name)_clap_name")
{
    this->setName("(default_clap_name)");
    std::cout << CYAN << "DiamondTrap " << this->getName() << " was created with default constructor" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name")
{
    this->setName(name);
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(FragTrap::getAttackDamage());
    std::cout << CYAN << "DiamondTrap " << this->getName() << " was created." << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << RED << "DiamondTrap " << this->getName() << " has been destroyed" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "Diamond " << this->getName() << " was copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy)
{
    std::cout << "Assignment operator for DiamondTrap called." << std::endl;
    FragTrap::operator=(copy);
    return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

std::string const &DiamondTrap::getName(void) const
{
    return (this->_name);
}

void DiamondTrap::setName(const std::string name)
{
    this->_name = name;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << YELLOW  << "I am DiamondTrap: " << this->_name << " and my ClapTrap name is: " 
              << ClapTrap::getName() << RESET << std::endl;
}