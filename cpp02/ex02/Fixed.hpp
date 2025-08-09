/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:35:04 by claudia           #+#    #+#             */
/*   Updated: 2025/07/29 16:36:19 by claudia          ###   ########.fr       */
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
        int              _value;
        static const int _frac;
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        Fixed(Fixed const &copy);
        Fixed &operator=(Fixed const &copy);
        Fixed operator+(Fixed const &copy)const;
        Fixed operator-(Fixed const &copy)const;
        Fixed operator*(Fixed const &copy)const;
        Fixed operator/(Fixed const &copy)const;
        bool  operator>(Fixed const &copy)const;
        bool  operator<(Fixed const &copy)const;
        bool  operator>=(Fixed const &copy)const;
        bool  operator<=(Fixed const &copy)const;
        bool  operator==(Fixed const &copy)const;
        bool  operator!=(Fixed const &copy)const;
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int value);
        Fixed operator--(int value);
        int   getRawBits(void) const;
        void  setRawBits(int const raw);
        static const Fixed &min(Fixed const &copy1, Fixed const &copy2);
        static const Fixed &max(Fixed const &copy1, Fixed const &copy2);
        static Fixed &min(Fixed &copy1, Fixed &copy2);
        static Fixed &max(Fixed &copy1, Fixed &copy2);
        float toFloat( void ) const;
        int   toInt( void ) const;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif