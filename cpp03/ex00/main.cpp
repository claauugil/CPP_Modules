/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:07:45 by claudia           #+#    #+#             */
/*   Updated: 2025/08/19 13:07:47 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void mario_adventure(void)
{
    ClapTrap mario("Mario");

    mario.attack("Goomba");
    mario.attack("Koopa Troopa");
    mario.attack("Bowser");
}

void luigi_adventure(void)
{
    ClapTrap luigi("Luigi");

    while (luigi.getHitPoints())
    {
        luigi.takeDamage(3);
        luigi.beRepaired(2);
    }
    luigi.takeDamage(1);
}

int main(void)
{
    std::cout << "\n\n🍄 Mario enters the Mushroom Kingdom!\n\n";
    mario_adventure();
    std::cout << "\n\n🍄 Luigi faces the dangers ahead!\n\n";
    luigi_adventure();
}
