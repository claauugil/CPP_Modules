/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:37:27 by claudia           #+#    #+#             */
/*   Updated: 2025/07/04 12:52:41 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main (void)
{
    int size;

    size = 20;
    Zombie *horde = zombieHorde(size, "Zombie");
    for (int i = 0; i < size; i++)
        horde[i].announce();
    delete[] horde;
}