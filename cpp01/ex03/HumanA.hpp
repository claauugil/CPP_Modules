/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:40:10 by claudia           #+#    #+#             */
/*   Updated: 2025/07/06 18:01:05 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name; 
        Weapon      &_weapon; // para que no pueda estar vacia
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack(void);
        void setWeapon(Weapon weapon);
};
