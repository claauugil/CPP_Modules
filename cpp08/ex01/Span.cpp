/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:18:29 by cgil              #+#    #+#             */
/*   Updated: 2026/01/14 17:28:51 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _maxSize(N){}

Span::Span(const Span& other)
    : _maxSize(other._maxSize), _numbers(other._numbers){}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxSize)
        throw FullException();
    _numbers.push_back(n);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> tmp(_numbers);
    std::sort(tmp.begin(), tmp.end());
    
    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = tmp[i] - tmp[i -1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}


// Exceptions
const char* Span::FullException::what() const throw()
{
    return "Span is full";
}

const char* Span::NoSpanException::what() const throw()
{
    return "Not enough elements to calculate a span";
}
