/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:25:17 by claudia           #+#    #+#             */
/*   Updated: 2025/08/08 17:43:37 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
    std::cout << CYAN << "ClapTrap " << this->_name << " constructed!" << RESET <<std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
    std::cout << CYAN <<"ClapTrap " << this->_name << " constructed!" << RESET  <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    if (this != &copy)
    {
        _name = copy._name;
        _hitPoints = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    std::cout<<"ClapTrap copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << RED <<"ClapTrap " << this->_name << " destroyed." << RESET << std::endl;
}

void ClapTrap:: attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << YELLOW << "ClapTrap " << _name  <<" attacks " << target
            << " ,causing " << _attackDamage << " points of damage!"
                << RESET << std::endl;
                _energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " can't attack! (HP: "
            << _hitPoints << ", Energy: " << _energyPoints << ")"
            << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0 )
    {
        _hitPoints -= amount;
        std::cout << YELLOW <<  "ClapTrap " << _name << " takes " << amount
              << " damage! Remaining HP: " << _hitPoints << RESET << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " cannot take damage, it is dead!" << std::endl;
    }
    if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << GREEN << "ClapTrap " << _name << " repairs itself for " << amount
		          << " points! New HP: " << _hitPoints << RESET << std::endl;
    }
    else
    {
        std::cout << BLUE << "ClapTrap " << _name << " can't repair itselt it has run out of energy!" << RESET << std::endl;
    }
}

std::string const &ClapTrap::getName(void) const
{
    return (this->_name);
}

int const &ClapTrap::getHitPoints(void)const
{
    return (this->_hitPoints);
}

int const &ClapTrap::getEnergyPoints(void)const
{
    return (this->_energyPoints);
}

int const &ClapTrap::getAttackDamage(void)const
{
    return (this->_attackDamage);
}

void ClapTrap::setName(std::string const &name)
{
    this->_name = name;
}

void ClapTrap::setHitPoints(int const &value)
{
    this->_hitPoints = value;
}

void ClapTrap::setEnergyPoints(int const &value)
{
    this->_energyPoints = value;
}

void ClapTrap::setAttackDamage(int const &value)
{
    this->_attackDamage= value;
}