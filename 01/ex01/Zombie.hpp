/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:56:28 by claudia           #+#    #+#             */
/*   Updated: 2025/07/06 14:12:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    
    private:
        std::string  _name;
    public:
        Zombie(std::string name);
        Zombie(void);
        ~Zombie(void);
        void announce(void);
        void setName(std::string name);
};

Zombie *newZombie(std::string name);

#endif