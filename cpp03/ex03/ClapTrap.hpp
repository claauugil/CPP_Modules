/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:04:52 by claudia           #+#    #+#             */
/*   Updated: 2025/08/08 13:29:21 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE   "\033[1;34m"
# define CYAN   "\033[1;36m"
# define RESET  "\033[0m"
# define RED	"\033[1;31m"

class ClapTrap
{
   private:
        std::string  _name;
        int          _hitPoints;
        int          _energyPoints;
        int          _attackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        
        // actions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string const &getName(void)const;
        int const &getHitPoints(void)const;
        int const &getEnergyPoints(void)const;
        int const &getAttackDamage(void)const;
        
        void setName(std::string const &name);
        void setHitPoints(int const &value);
        void setEnergyPoints(int const &value);
        void setAttackDamage(int const &value);
};

#endif