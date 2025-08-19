/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:08:48 by claudia           #+#    #+#             */
/*   Updated: 2025/08/19 13:08:50 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{       
    public:
        FragTrap(void);
        FragTrap(std::string const &name);
        FragTrap(FragTrap const &copy);
        ~FragTrap(void);
        
        FragTrap &operator=(FragTrap const &copy);
        
        void highFivesGuys(void);
};

#endif