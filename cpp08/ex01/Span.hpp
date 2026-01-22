/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:18:21 by cgil              #+#    #+#             */
/*   Updated: 2026/01/14 17:22:38 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int    _maxSize;
        std::vector<int> _numbers;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n );
        template <typename It>
        void addNumber(It begin, It end)
        {
            if (_numbers.size() + std::distance(begin, end) > _maxSize)
                throw FullException();
            _numbers.insert(_numbers.end(), begin, end);
        }
        
        int shortestSpan() const;
        int longestSpan() const;

        class FullException : public std::exception
        {
            const char* what() const throw();
        }; 
        class NoSpanException : public std::exception
        {
            const char* what() const throw();
        };
};

#endif
