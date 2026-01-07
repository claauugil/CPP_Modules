/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:08:26 by cgil              #+#    #+#             */
/*   Updated: 2026/01/07 12:46:53 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#define CYAN   "\033[36m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

int main()
{
    // int
    std::cout << CYAN << "---------------Running tests:---------------\n" << RESET;
    std::cout << GREEN << "Type: int\n" << RESET;
    int a = 2;
    int b = 3;

    std::cout << "Before swap: a = " << CYAN << a << RESET << ", b = " << CYAN << b << RESET << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << CYAN << a << RESET << ", b = " << CYAN << b << RESET << std::endl;

    std::cout << "min(a, b) = " << CYAN << ::min(a, b) << RESET << std::endl;
    std::cout << "max(a, b) = " << CYAN << ::max(a, b) << RESET << std::endl;

    std::cout << CYAN << "--------------------------------------------" << RESET << std::endl;

    // string
    std::cout << GREEN << "Type: std::string\n" << RESET;
    std::string c = "chain1";
    std::string d = "chain2";

    std::cout << "Before swap: c = " << CYAN << c << RESET << ", d = " << CYAN << d << RESET << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << CYAN << c << RESET << ", d = " << CYAN << d << RESET << std::endl;

    std::cout << "min(c, d) = " << CYAN << ::min(c, d) << RESET << std::endl;
    std::cout << "max(c, d) = " << CYAN << ::max(c, d) << RESET << std::endl;

    std::cout << CYAN << "--------------------------------------------" << RESET << std::endl;
    // float
    std::cout << GREEN << "Type: float\n" << RESET;
    float e = 4.5f;
    float f = 2.3f;

    std::cout << "Before swap: e = " << CYAN << e << RESET << ", f = " << CYAN << f << RESET << std::endl;
    ::swap(e, f);
    std::cout << "After swap: e = " << CYAN << e << RESET << ", f = " << CYAN << f << RESET << std::endl;

    std::cout << "min(e, f) = " << CYAN << ::min(e, f) << RESET << std::endl;
    std::cout << "max(e, f) = " << CYAN << ::max(e, f) << RESET << std::endl;

    return 0;
}

