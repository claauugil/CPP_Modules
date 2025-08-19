/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:07:26 by claudia           #+#    #+#             */
/*   Updated: 2025/08/19 13:07:27 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void mario_adventure(void)
{
    FragTrap mario("Mario");

    mario.attack("Goomba");
    mario.attack("Koopa Troopa");
    mario.attack("Bowser");
    mario.highFivesGuys();
}

void luigi_adventure(void)
{
    FragTrap luigi("Luigi");

    while (luigi.getHitPoints() > 0)
    {
        luigi.takeDamage(20);
        luigi.beRepaired(10);
    }
    luigi.takeDamage(1);
    luigi.highFivesGuys();
    
}

int main(void)
{
    std::cout << "\n\n🍄 Mario enters the Mushroom Kingdom!\n\n";
    mario_adventure();
    std::cout << "\n\n🍄 Luigi faces the dangers ahead!\n\n";
    luigi_adventure();
}
