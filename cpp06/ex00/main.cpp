/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:11:03 by cgil              #+#    #+#             */
/*   Updated: 2026/01/06 13:58:02 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ()
{
    std::string tests[] = {
        "a"
        "0",
        "42",
        "-42",
        "2147483647",
        "-2147483648",
        "42.0f",
        "-4.2f",
        "42.42",
        "-42.42",
        "0.0",
        "nan",
        "nanf",
        "+inf",
        "-inf",
        "+inff",
        "-inff",
        "!"
    };
    
    size_t n = sizeof(tests) / sizeof(tests[0]);
    for (size_t i = 0; i < n; i++)
    {
        std::cout << GREEN << "=== Test: " << tests[i] << " ===" << RESET << std::endl;
        ScalarConverter::convert(tests[i]);
        std::cout << std::endl;
    }
    return (0);
}
