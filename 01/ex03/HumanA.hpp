/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:40:10 by claudia           #+#    #+#             */
/*   Updated: 2025/07/10 20:27:42 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name; 
        Weapon      &_weapon; // so it can't be empty
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack(void);
        void setWeapon(Weapon weapon);
};
