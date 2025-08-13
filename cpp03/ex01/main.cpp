/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:40:53 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/08 18:09:18 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void mario_adventure(void)
{
    ScavTrap mario("Mario");

    mario.attack("Goomba");
    mario.attack("Koopa Troopa");
    mario.attack("Bowser");
    mario.guardGate();
}

void luigi_adventure(void)
{
    ScavTrap luigi("Luigi");

    while (luigi.getHitPoints())
    {
        luigi.takeDamage(20);
        luigi.beRepaired(10);
    }
    luigi.takeDamage(1);
    luigi.guardGate();
}

int main(void)
{
    std::cout << "\n\n🍄 Mario enters the Mushroom Kingdom!\n\n";
    mario_adventure();
    std::cout << "\n\n🍄 Luigi faces the dangers ahead!\n\n";
    luigi_adventure();
}
