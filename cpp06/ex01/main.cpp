/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:26:26 by cgil              #+#    #+#             */
/*   Updated: 2026/01/06 13:59:02 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data d;
    d.value = 42;

    Data* original = &d;
    uintptr_t raw = Serializer::serialize(original);
    Data* recovered = Serializer::deserialize(raw);
    std::cout << YELLOW << "Original ptr: " << RESET << original << std::endl;
    std::cout << YELLOW << "Serialized ptr: " << RESET << raw << std::endl;
    std::cout << YELLOW << "Recovered ptr: " << RESET << recovered << std::endl;
    std::cout << YELLOW << "Value: " << RESET << recovered->value << std::endl;
}
