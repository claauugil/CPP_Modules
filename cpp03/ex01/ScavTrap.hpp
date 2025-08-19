/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:09:28 by claudia           #+#    #+#             */
/*   Updated: 2025/08/19 12:22:10 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{       
    public:
        ScavTrap(void);
        ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &copy);
        ~ScavTrap(void);
        
        ScavTrap &operator=(ScavTrap const &copy);
        
        void guardGate(void);
        void attack(const std::string& target);
};

#endif