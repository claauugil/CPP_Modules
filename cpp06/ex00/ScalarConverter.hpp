/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:47:05 by claudia           #+#    #+#             */
/*   Updated: 2026/01/06 13:58:14 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <limits>
#include <climits> 
#include <cmath>
#include <string>
#include <cstdlib>
#include <cctype>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &rhs);
        ~ScalarConverter(void);

        static bool isChar(const std::string &s);
        static bool isInt(const std::string &s);
        static bool isFloat(const std::string &s);
        static bool isDouble(const std::string &s);
        static bool isPseudoLiteral(const std::string &s);

        static void fromChar(char c);
        static void fromInt(const std::string &s);
        static void fromFloat(const std::string &s);
        static void fromDouble(const std::string &s);
        static void printPseudoLiteral(const std::string &s);

        static void printChar(double d);
        static void printInt(double d);  
        static void printFloat(double d);
        static void printDouble(double d);   
           
    public:
        static void convert(const std::string &literal);
};

#endif
