/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:20:19 by claudia           #+#    #+#             */
/*   Updated: 2025/07/02 19:30:35 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

int main ()
{
    Zombie *heapZombie = newZombie("Heapy");
    heapZombie->announce();
    
    randomChump("Stacky");
    delete heapZombie;
    return (0);
}