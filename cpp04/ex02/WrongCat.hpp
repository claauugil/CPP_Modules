/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:43:29 by cgil              #+#    #+#             */
/*   Updated: 2025/09/01 13:43:36 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE   "\033[1;34m"
# define CYAN   "\033[1;36m"
# define RESET  "\033[0m"
# define RED	"\033[1;31m"

class WrongCat: public WrongAnimal 
{
   public:
        WrongCat(void);
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
        ~WrongCat(void);
   
    void makeSound(void) const;
};

#endif