/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:06:22 by cgil              #+#    #+#             */
/*   Updated: 2026/01/07 12:54:43 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define CYAN   "\033[36m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RED    "\033[31m"
#define RESET  "\033[0m"

int main()
{
    std::cout << CYAN << "---------------Running tests:---------------\n" << RESET;

   //  int
    std::cout << GREEN << "Type: int\n" << RESET;
    Array<int> intArray(5);

    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;

    std::cout << "intArray contents: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << CYAN << intArray[i] << " " << RESET;
    std::cout << std::endl;

    std::cout << CYAN << "--------------------------------------------\n" << RESET;
    
    // unsigned  int
    std::cout << GREEN << "Type: unsigned int\n" << RESET;
    Array<unsigned int> uintArray(5);
    for (size_t i = 0; i < uintArray.size(); i++)
        std::cout << uintArray[i] << " ";
    std::cout << std::endl;
    
    std::cout << CYAN << "--------------------------------------------\n" << RESET;
            
    // copy test
    std::cout << GREEN << "Copy test (deep copy)\n" << RESET;
    Array<int> copyArray = intArray;
    copyArray[0] = 42;

    std::cout << "Original[0]: " << CYAN << intArray[0] << RESET << std::endl;
    std::cout << "Copy[0]: " << CYAN << copyArray[0] << RESET << std::endl;

    std::cout << CYAN << "--------------------------------------------\n" << RESET;

    // string
    std::cout << GREEN << "Type: std::string\n" << RESET;
    Array<std::string> strArray(3);

    strArray[0] = "hello";
    strArray[1] = "cpp";
    strArray[2] = "array";

    for (unsigned int i = 0; i < strArray.size(); i++)
        std::cout << CYAN << strArray[i] << " " << RESET;
    std::cout << std::endl;

    std::cout << CYAN << "--------------------------------------------\n" << RESET;

    // exception
    std::cout << GREEN << "Exception test\n" << RESET;
    try
    {
        std::cout << intArray[8] << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << RED << "Exception caught: index out of bounds\n" << RESET;
    }

    std::cout << CYAN << "--------------------------------------------\n" << RESET;

    return 0;
}
