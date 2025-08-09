/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:35:01 by claudia           #+#    #+#             */
/*   Updated: 2025/07/29 16:36:04 by claudia          ###   ########.fr       */
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
    
}
Fixed:: Fixed(const int value): _value(value * ft_pow(2, this->_frac))
{
    
}
Fixed:: Fixed(const float value): _value(roundf(value * ft_pow(2, this->_frac)))
{
    
}
Fixed::Fixed(Fixed const & copy)
{
    *this = copy;
}

Fixed::~Fixed(void)
{
    
}

Fixed Fixed::operator+(Fixed const &copy) const
{
    Fixed   result(this->toFloat() + copy.toFloat());
    return (result);
}

Fixed Fixed::operator-(Fixed const &copy) const
{
    Fixed   result(this->toFloat() - copy.toFloat());
    return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed Fixed::operator/(Fixed const &copy) const
{
    Fixed   result(this->toFloat() / copy.toFloat());
    return (result);
}

bool Fixed::operator==(const Fixed &copy) const
{
    return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!=(const Fixed &copy) const
{
    return (this->toFloat() != copy.toFloat());
}

bool Fixed::operator<=(const Fixed &copy) const
{
    return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator>=(const Fixed &copy) const
{
    return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator<(const Fixed &copy) const
{
    return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator>(const Fixed &copy) const
{
    return (this->toFloat() > copy.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++(int value)
{
    Fixed aux;

    aux = *this;
    if(!value)
        value = 1;
    this->setRawBits(this->getRawBits() + value);
    return (aux);
}

Fixed Fixed::operator--(int value)
{
    Fixed aux;

    aux = *this;
    if(!value)
        value = 1;
    this->setRawBits(this->getRawBits() - value);
    return (aux);
}

Fixed &Fixed::operator=(Fixed const &copy)
{
    this->_value = copy.getRawBits();
    return (*this);
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

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;   
}

const Fixed &Fixed::min(Fixed const &copy1, Fixed const &copy2)
{
    if (copy1 < copy2)
        return (copy1);
    return (copy2);
}
Fixed &Fixed::min(Fixed &copy1, Fixed &copy2)
{
    if (copy1 < copy2)
        return (copy1);
    return (copy2);
}
const Fixed &Fixed::max(Fixed const &copy1, Fixed const &copy2)
{
    if (copy1 > copy2)
        return (copy1);
    return (copy2);
}

Fixed &Fixed::max(Fixed &copy1, Fixed &copy2)
{
    if (copy1 < copy2)
        return (copy1);
    return (copy2);
}