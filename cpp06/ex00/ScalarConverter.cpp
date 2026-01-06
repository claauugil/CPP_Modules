/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:06:05 by cgil              #+#    #+#             */
/*   Updated: 2026/01/06 13:58:09 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &s)
{
    return (s.length() == 1 && isprint(s[0]));
}

bool ScalarConverter::isInt(const std::string &s)
{
    if (s.empty())
        return false;
    char *end;
    errno = 0;
    long val = std::strtol(s.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || val < INT_MIN || val > INT_MAX)
        return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string &s)
{
    if (s.empty() || s[s.length() - 1] != 'f')
        return false;
    char *end;
    errno = 0;
    std::strtof(s.c_str(), &end);
    return (*end == 'f' && errno != ERANGE);
}

bool ScalarConverter::isDouble(const std::string &s)
{
    if (s.empty())
        return false;
    char *end;
    errno = 0;
    std::strtod(s.c_str(), &end);
    return (*end == '\0' && errno != ERANGE);
}

bool ScalarConverter::isPseudoLiteral(const std::string &s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

/* =================== print helpers =================== */

void ScalarConverter::printChar(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127 || d != static_cast<int>(d))
        std::cout << RED << "char: impossible\n" << RESET;
    else if (!isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
}

void ScalarConverter::printInt(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << RED << "int: impossible\n" << RESET;
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
}

void ScalarConverter::printFloat(double d)
{
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf\n";
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inff\n" : "-inff\n");
    else
    {
        float f = static_cast<float>(d);
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";
    }
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf\n" : "-inf\n");
    else
        std::cout << std::fixed << std::setprecision(1) << d << "\n";
}

/* =================== converters =================== */

void ScalarConverter::fromChar(char c)
{
    double d = static_cast<double>(c);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::fromInt(const std::string &s)
{
    long val = std::strtol(s.c_str(), 0, 10);
    double d = static_cast<double>(val);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::fromFloat(const std::string &s)
{
    double d = static_cast<double>(std::strtof(s.c_str(), 0));
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::fromDouble(const std::string &s)
{
    double d = std::strtod(s.c_str(), 0);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::printPseudoLiteral(const std::string &s)
{
    std::cout << RED << "char: impossible\nint: impossible\n" << RESET;
    if (s == "nan" || s == "nanf")
    {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    else if (s == "+inf" || s == "+inff")
    {
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
    else if (s == "-inf" || s == "-inff")
    {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isPseudoLiteral(literal))
        printPseudoLiteral(literal);
    else if (isChar(literal))
        fromChar(literal[0]);
    else if (isInt(literal))
        fromInt(literal);
    else if (isFloat(literal))
        fromFloat(literal);
    else if (isDouble(literal))
        fromDouble(literal);
    else
        std::cout << RED << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n" << RESET;
}
