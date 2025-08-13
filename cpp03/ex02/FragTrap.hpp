/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:09:28 by claudia           #+#    #+#             */
/*   Updated: 2025/08/08 19:30:07 by cgil             ###   ########.fr       */
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