/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:57 by cgil              #+#    #+#             */
/*   Updated: 2026/01/14 17:28:00 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN  "\033[36m"
#define RED    "\033[31m"
#define YELLOW "\033[33m"

void printVector(const std::vector<int>& v)
{
    std::cout << "[ ";
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));

    std::cout << CYAN << "========== BASIC TEST ==========" << RESET << std::endl;
    try
    {
        Span sp(5);

        int values[] = {6, 3, 17, 9, 11};
        std::vector<int> input(values, values + 5);

        std::cout << "Values added to Span : ";
        printVector(input);

        for (size_t i = 0; i < input.size(); ++i)
            sp.addNumber(input[i]);

        std::cout << "Shortest span        : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span         : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Exception            : " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "====== FULL SPAN EXCEPTION =====" << RESET << std::endl;
    try
    {
        Span sp(2);
        std::vector<int> input;
        input.push_back(1);
        input.push_back(2);
        input.push_back(3);

        std::cout << "Attempting to add    : ";
        printVector(input);

        for (size_t i = 0; i < input.size(); ++i)
            sp.addNumber(input[i]);
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "==== INVALID SPAN EXCEPTION ====" << RESET << std::endl;
    try
    {
        Span sp(1);
        std::cout << "Values added to Span : [ 42 ]" << std::endl;
        sp.addNumber(42);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "======= ITERATOR RANGE ========" << RESET << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(100);
        v.push_back(200);
        v.push_back(300);

        std::cout << "Vector used as range : ";
        printVector(v);

        Span sp(5);
        sp.addNumber(v.begin(), v.end());

        std::cout << "Additional values    : [ 450 470 ]" << std::endl;
        sp.addNumber(450);
        sp.addNumber(470);

        std::cout << "Shortest span        : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span         : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Exception            : " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "======== STRESS TEST ==========" << RESET << std::endl;
    try
    {
        Span sp(10000);

        std::cout << "Adding numbers       : 10,000 random values" << std::endl;
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand());

        std::cout << "Shortest span        : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span         : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Exception            : " << e.what() << RESET << std::endl;
    }

    return 0;
}



// ==== MAIN EXAMPLE FROM SUBJECT ======
/*int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}*/
