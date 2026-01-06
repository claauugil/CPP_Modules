/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:26:29 by cgil              #+#    #+#             */
/*   Updated: 2026/01/06 13:59:09 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
    // Converts the object's address to an integer without modifying the object
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    // Converts an integer back into a pointer to the original object
    return (reinterpret_cast<Data*>(raw));
}
