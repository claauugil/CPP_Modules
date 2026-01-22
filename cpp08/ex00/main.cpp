/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:08:26 by cgil              #+#    #+#             */
/*   Updated: 2026/01/14 17:21:48 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define CYAN   "\033[36m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RED    "\033[31m"
#define RESET  "\033[0m"

int main()
{
    std::cout << CYAN << "---------------Running tests:---------------\n" << RESET;

    // Vector test
    std::cout << GREEN << "Container: std::vector<int>\n" << RESET;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "Vector contents: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << CYAN << vec[i] << " " << RESET;
    std::cout << std::endl;

    std::cout << CYAN << "--------------------------------------------\n" << RESET;

    std::cout << GREEN << "Search test\n" << RESET;
    try
    {
        std::vector<int>::iterator it_vec = easyfind(vec, 3);
        std::cout << "Found value: " << CYAN << *it_vec << RESET << std::endl;

        it_vec = easyfind(vec, 10);
        std::cout << "Found value: " << CYAN << *it_vec << RESET << std::endl; // Will not run
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << "--------------------------------------------\n" << RESET;

    // List test
    std::cout << GREEN << "Container: std::list<int>\n" << RESET;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << CYAN << *it << " " << RESET;
    std::cout << std::endl;

    std::cout << CYAN << "--------------------------------------------\n" << RESET;

    std::cout << GREEN << "Search test\n" << RESET;
    try
    {
        std::list<int>::iterator it_lst = easyfind(lst, 20);
        std::cout << "Found value: " << CYAN << *it_lst << RESET << std::endl;
        std::cout << CYAN << "--------------------------------------------\n" << RESET;
        std::cout << GREEN << "Searching for value not in container" << RESET << std:: endl;
        it_lst = easyfind(lst, 50);
        std::cout << "Found value: " << CYAN << *it_lst << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << "--------------------------------------------\n" << RESET;

    return 0;
}

