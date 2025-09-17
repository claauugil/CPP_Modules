/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:40:40 by claudia           #+#    #+#             */
/*   Updated: 2025/08/15 11:59:02 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE   "\033[1;34m"
# define CYAN   "\033[1;36m"
# define RESET  "\033[0m"
# define RED	"\033[1;31m"

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(std::string const &type);
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual ~Animal(void);
        
        std::string const   &getType(void) const;
        void                setType(std::string const &type);
        
        virtual void makeSound(void)const;
};

#endif
