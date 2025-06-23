/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:59:35 by claudia           #+#    #+#             */
/*   Updated: 2025/06/23 17:53:10 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main (void)
{
    Phonebook   ph1;
    std::string str;

    while (str != "EXIT")
    {
        std::cout << "Enter a command > ";
        std::getline(std::cin, str);
        if (str == "ADD")
            ph1.add();
        else if (str == "SEARCH")
            ph1.search();
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return (0);
        }
    }
    return (0);
}