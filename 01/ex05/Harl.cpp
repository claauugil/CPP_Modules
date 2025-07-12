/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:10:54 by claudia           #+#    #+#             */
/*   Updated: 2025/07/07 17:57:34 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Harl has been created" << std::endl;
}

Harl::~Harl(void)
{
    std::cout << RED "Harl has been destroyed" << DEFAULT;
}

void    Harl::debug(void)
{
    std::cout << PINK << "[DEBUG]" << DEFAULT;
    std::cout << "I love to get extra bacon for my ";
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
    std::cout << " I just love it!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << LIGHT_BLUE << "[INFO]" << DEFAULT;
    std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl;
}
void    Harl::warning(void)
{
    std::cout << YELLOW << "[WARNING]" << DEFAULT;
    std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl;
}
void    Harl::error(void)
{
    std::cout << RED << "[ERROR]" << DEFAULT;
    std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*ptr_complain[i])();
            break ;
        }
    }
}
