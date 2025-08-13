/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:32:07 by claudia           #+#    #+#             */
/*   Updated: 2025/08/12 17:41:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE   "\033[1;34m"
# define CYAN   "\033[1;36m"
# define RESET  "\033[0m"
# define RED	"\033[1;31m"

class DiamondTrap : public ScavTrap, public FragTrap 
{
    private:
        std::string _name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string const &name);
        DiamondTrap(DiamondTrap const &copy);
        DiamondTrap &operator=(DiamondTrap const &copy);
        ~DiamondTrap(void);
        
        std::string const &getName(void) const;
        void setName(std::string const name);
        
        void attack(const std::string &target);
        void whoAmI(void);
};

#endif
