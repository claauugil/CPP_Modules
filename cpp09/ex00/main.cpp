/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:08:26 by cgil              #+#    #+#             */
/*   Updated: 2026/01/23 12:09:55 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED << "Error: could not open file" << RESET << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try {
        btc.loadDatabase("data.csv");
        btc.processInput(argv[1]);
    }
    catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return 1;
    }
    return (0);
}

