/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:06:22 by cgil              #+#    #+#             */
/*   Updated: 2026/01/14 17:29:59 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

#define CYAN  "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main()
{
    std::cout << CYAN << "====== BASIC STACK TEST ======" << RESET << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top element: " << YELLOW << mstack.top() << RESET << std::endl;

        mstack.pop();
        std::cout << "Size after pop: " << YELLOW << mstack.size() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "====== ITERATOR TEST =========" << RESET << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Forward iteration: ";
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << YELLOW << *it << RESET << " ";
            ++it;
        }
        std::cout << std::endl;

        std::cout << "Reverse iteration: ";
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        while (rit != rite)
        {
            std::cout << YELLOW << *rit << RESET << " ";
            ++rit;
        }
        std::cout << std::endl;
    }

    std::cout << "\n" << CYAN << "====== COPY TEST =============" << RESET << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        std::stack<int> copy(mstack);

        std::cout << "Top of copied std::stack: "
                  << YELLOW << copy.top() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "==== COMPARISON WITH std::list" << RESET << std::endl;
    {
        MutantStack<int> mstack;
        std::list<int>   lst;

        mstack.push(1);
        mstack.push(2);
        mstack.push(3);

        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);

        std::cout << "MutantStack: ";
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << YELLOW << *it << RESET << " ";
            ++it;
        }

        std::cout << "\nstd::list:   ";
        std::list<int>::iterator lit = lst.begin();
        std::list<int>::iterator lite = lst.end();
        while (lit != lite)
        {
            std::cout <<  YELLOW << *lit << RESET << " ";
            ++lit;
        }
        std::cout << std::endl;
    }
    return 0;
}

/*int main()
{
    MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}*/
