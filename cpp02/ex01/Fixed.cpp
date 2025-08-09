/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:35:01 by claudia           #+#    #+#             */
/*   Updated: 2025/07/24 19:33:20 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac = 8;

static float ft_pow(float base, int exp)
{
    float result;

    if (!exp)
        return (1);
    if (exp < 0)
    {
        base = 1 / base;
        exp *= -1;
    }
    result = base;
    while (--exp)
        result *= base;
    return (result);
}

Fixed::Fixed(void): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
// converts normal int into fixed-point
Fixed:: Fixed(const int value): _value(value * ft_pow(2, this->_frac))
{
    std::cout << "Int constuctor called" << std::endl;
}
// converts floating-point number into fixed-point
Fixed:: Fixed(const float value): _value(roundf(value * ft_pow(2, this->_frac)))
{
    std::cout << "Float constuctor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
    std::cout <<"Copy constructor called" << std::endl;
    *this = copy;
}

// returns reference to current object
Fixed &Fixed::operator=(Fixed const &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;   
}

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
    return (str << fixed_nbr.toFloat());
}

float Fixed::toFloat()const
{
    return (this->_value * ft_pow(2, -this->_frac));
}

int Fixed::toInt(void) const
{
    return (this->_value * ft_pow(2, -this->_frac));
}
