/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:40:53 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/13 15:42:20 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void mario_adventure(void)
{
    DiamondTrap mario("Mario");

    mario.attack("Goomba");
    mario.attack("Koopa Troopa");
    mario.attack("Bowser");
    mario.guardGate();
    mario.whoAmI();
}

void luigi_adventure(void)
{
    DiamondTrap luigi("Luigi");

    while (luigi.getHitPoints() > 0)
    {
        luigi.takeDamage(20);
        luigi.beRepaired(10);
    }
    luigi.takeDamage(1);
    luigi.highFivesGuys();
    luigi.whoAmI();
    
}

int main(void)
{
    std::cout << "\n\n🍄 Mario enters the Mushroom Kingdom!\n\n";
    mario_adventure();
    std::cout << "\n\n🍄 Luigi faces the dangers ahead!\n\n";
    luigi_adventure();
}
