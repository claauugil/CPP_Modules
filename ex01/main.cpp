/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:59:35 by claudia           #+#    #+#             */
/*   Updated: 2025/06/24 17:37:48 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main (void)
{
    Phonebook   phone;
    std::string input;

    while (input != "EXIT")
    {
        std::cout << "Enter a command > ";
        std::getline(std::cin, input);
        if (input == "ADD")
            phone.add();
        else if (input == "SEARCH")
            phone.search();
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return (0);
        }
    }
    return (0);
}