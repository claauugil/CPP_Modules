/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:10:47 by claudia           #+#    #+#             */
/*   Updated: 2025/07/07 18:42:25 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void harl_switch(char *argv, Harl & h)
{
    switch (harl_translate(argv))
    {
        case 0:
            h.complain("DEBUG");
        case 1:
            h.complain("INFO");
        case 2:
            h.complain("WARNING");
        case 3:
            h.complain("ERROR");
            break;
        default:
            std::cout << "[Probably complaining about insignificant problems ]" << std::endl;
    }
}

int main (int argc, char **argv)
{
    Harl h;
    
    if (argc != 2)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    else
        harl_switch(argv[1], h);
    return (0);
}