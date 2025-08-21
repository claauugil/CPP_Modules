/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:15:40 by claudia           #+#    #+#             */
/*   Updated: 2025/08/21 10:49:41 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Unnamed ScavTrap")
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap from ClapTrap " << this->getName() << " created with default constructor" << std::endl;
}
ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap from ClapTrap " << this->getName() << " was created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap " << this->getName() << " was copied" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << RED << "ScavTrap from ClapTrap " << this->getName() << " was destroyed" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
    std::cout << "Assignment operator for ScavTrap called." << std::endl;
    ClapTrap::operator=(copy);
    return (*this);
}

void ScavTrap:: attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << YELLOW << "ScavTrap " << _name  <<" attacks " << target
            << ", causing " << _attackDamage << " points of damage!"
                << RESET << std::endl;
                _energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " can't attack! (HP: "
            << _hitPoints << ", Energy: " << _energyPoints << ")"
            << std::endl;
    }
}

void ScavTrap::guardGate(void)
{
    if (this->getHitPoints() > 0)
        std::cout << "ScavTrap from ClapTrap " << this->getName() << " is now in Gate Keeper mode" << std::endl;
    else
        std::cout << "Cannot switch to gate-keeper mode since ClapTrap " << this->getName() << " is dead." << std::endl;
}