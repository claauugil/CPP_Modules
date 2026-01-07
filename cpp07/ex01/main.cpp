/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:57 by cgil              #+#    #+#             */
/*   Updated: 2026/01/07 12:50:55 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#include <iostream>
#include "iter.hpp"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN  "\033[36m"
#define YELLOW "\033[33m"

// does not modify the element
template <typename T>
void printElem(const T &elem)
{
    std::cout << CYAN << elem << RESET << " ";
}

// modifies the element
void increment(int &n)
{
    n++;
}

int main()
{
    std::cout << CYAN << "---------------Running iter tests:-------------\n" << RESET;

    // int (modifiable)
    std::cout << GREEN << "Type: int (modifiable)\n" << RESET;
    int arr[] = {1, 2, 3, 4};

    std::cout << "Before increment: ";
    iter(arr, 4, printElem<int>);
    std::cout << std::endl;

    iter(arr, 4, increment);

    std::cout << "After increment:  ";
    iter(arr, 4, printElem<int>);
    std::cout << std::endl;

    std::cout << CYAN << "-----------------------------------------------\n" << RESET;

    // const int
    std::cout << GREEN << "Type: const int\n" << RESET;
    const int constArr[] = {10, 20, 30};

    std::cout << "Array values: ";
    iter(constArr, 3, printElem<int>);
    std::cout << std::endl;

    std::cout << CYAN << "-----------------------------------------------\n" << RESET;

    // std::string
    std::cout << GREEN << "Type: std::string\n" << RESET;
    std::string strArr[] = {"hello", "iter", "templates"};

    std::cout << "Array values: ";
    iter(strArr, 3, printElem<std::string>);
    std::cout << std::endl;

    return 0;
}
