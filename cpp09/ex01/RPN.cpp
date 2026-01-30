/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:13:41 by cgil              #+#    #+#             */
/*   Updated: 2026/01/23 19:03:50 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other)
{
    _stack = other._stack;
}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN(){}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isDigit(char c) const
{
    return c >= '0' && c <= '9';
}

void RPN::performOperation(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough operands");
        
    int b = _stack.top(); 
    _stack.pop(); // extract element
    int a = _stack.top();
    _stack.pop();
    
    switch (op)
    {
        case '+':
            _stack.push(a + b);
            break;
        case '-':
            _stack.push(a - b);
            break;
        case '*':
            _stack.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            _stack.push(a / b);
            break;
        default:
            throw std::runtime_error("Error: unknown operator");
    }
}

int RPN::calculateRPN(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (token.length() == 1 && isOperator(token[0]))
            performOperation(token[0]);
        else if (token.length() == 1 && isDigit(token[0]))
            _stack.push(token[0] - '0'); // convert char to int
        else 
            throw std::runtime_error("Error: invalid token");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    return _stack.top();
}
