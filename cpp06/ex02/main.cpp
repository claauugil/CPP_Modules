/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:01:50 by cgil              #+#    #+#             */
/*   Updated: 2026/01/06 14:01:10 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"

Base *generate()
{
    std::cout << YELLOW <<"Generated object" << RESET << std::endl;
    int r = rand() % 3;
    if (r == 0)
        return (new A());
    else if (r == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    if (!p)
        return ;
    if (dynamic_cast<A*>(p))
        std::cout << GREEN << "Object type: " << RESET << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << GREEN << "Object type: " << RESET << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << GREEN << "Object type: " << RESET << "C\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << GREEN << "Object type: " << RESET << "A\n";
        return ;
    } catch (...){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << GREEN << "Object type: " << RESET << "B\n";
        return ;
    } catch (...){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << GREEN << "Object type: " << RESET << "C\n";
        return ;
    } catch (...){}
}

int main ()
{
    srand(static_cast<unsigned int>(time(NULL)));
    Base *obj = generate();
    std::cout << "Identified by pointer:" << std::endl;
    identify(obj);
    std::cout << "Identified by reference:" << std::endl;
    identify(*obj);
    delete obj;
    return (0);
}
