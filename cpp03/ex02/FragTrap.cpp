/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:15:40 by claudia           #+#    #+#             */
/*   Updated: 2025/08/12 16:20:50 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Unnamed FragTrap")
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << CYAN <<"FragTrap from ClapTrap " << this->getName() << " created with default constructor" << RESET << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << CYAN << "FragTrap from ClapTrap " << this->getName() << " was created." << RESET <<  std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
    std::cout << "Assignment operator for FragTrap called." << std::endl;
    ClapTrap::operator=(copy);
    return (*this);
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "FragTrap from ClapTrap " << this->getName() << " copied." << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << RED <<"FragTrap from ClapTrap " << this->getName() << " was destroyed" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this-> getHitPoints()> 0)
        std::cout << YELLOW <<"FragTrap from FragTrap: " << this->getName() << " says: \"HIGH FIVE EVERYONE!\"" << RESET << std::endl;
    else
        std::cout << RED << "Cannot high five: FragTrap " << this->getName() << " is dead." << RESET << std::endl;
}