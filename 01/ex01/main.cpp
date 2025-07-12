/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:37:27 by claudia           #+#    #+#             */
/*   Updated: 2025/07/06 14:34:30 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*horde;
	int		N = 3;

	horde = zombieHorde(N, "Horde");
 	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	delete[] horde; //for leaks when we use new
	return (0);
}