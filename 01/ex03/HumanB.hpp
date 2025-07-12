/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:49:13 by claudia           #+#    #+#             */
/*   Updated: 2025/07/10 20:29:07 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon      *_weapon; // the weapon does not need to be created, it can be null at the beginning.
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void attack(void);
        void setWeapon(Weapon &weapon);
};