/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:35:04 by claudia           #+#    #+#             */
/*   Updated: 2025/07/24 18:48:59 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>


// represents numbers in fixed-point format
// where the coma is in a fixed position

// the fractional bits must be 8, so the last 8 bits are
// the decimal part 2²256

class Fixed
{
    private:
        int              _value;              // fixed point value
        static const int _frac;               // fractional bits
    public:
        Fixed(void);                         // deafult
        Fixed(Fixed const &copy);            // copy constructor
        Fixed &operator=(Fixed const &copy); // copy assignment operator overload
        Fixed(const int value);              // int constructor
        Fixed(const float value);            // float constructor 
        ~Fixed(void);                        // destructor
        
        int   getRawBits(void) const;
        void  setRawBits(int const raw);
        
        float toFloat( void ) const; // converts fixed-point to floating point
        int   toInt( void ) const; // converts fixed-point to integer
};

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif