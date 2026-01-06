/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:26:34 by cgil              #+#    #+#             */
/*   Updated: 2026/01/06 13:59:15 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

#define RESET   "\033[0m"
#define YELLOW  "\033[1;33m"

struct Data;

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &rhs);
        ~Serializer(void);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
