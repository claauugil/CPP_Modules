/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:57:20 by cgil              #+#    #+#             */
/*   Updated: 2026/01/23 15:18:11 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>   
#include <cstdlib>
#include <cctype>
#include <exception>

#define CYAN   "\033[36m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RED    "\033[31m"
#define RESET  "\033[0m"

class RPN
{
    private:
        std::stack<int> _stack;

        bool isOperator(char c)const;
        void performOperation(char op);
        bool isDigit(char c) const;

    public:
        RPN();
        RPN(const RPN& other);
        RPN &operator=(const RPN& other);
        ~RPN();
        // principal function
        int calculateRPN(const std::string& expression);
};

#endif