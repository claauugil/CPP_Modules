/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:57 by cgil              #+#    #+#             */
/*   Updated: 2026/01/26 11:20:37 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: usage: ./RPN \"expression\"\n" << RESET;
        return 1;
    }
    try {
        RPN rpn;
        int result = rpn.calculateRPN(argv[1]);
        std::cout << CYAN << result << RESET << std::endl;
    } catch (const std::exception &e){
        std::cerr << RED <<e.what() << RESET << std::endl;
        return 1;
    }
    return 0;
}
