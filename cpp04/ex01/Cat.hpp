/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:50:27 by claudia           #+#    #+#             */
/*   Updated: 2025/09/01 13:39:45 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE   "\033[1;34m"
# define CYAN   "\033[1;36m"
# define RESET  "\033[0m"
# define RED	"\033[1;31m"

class Cat: public Animal 
{
    private:
        Brain *_brain;
    public:
        Cat(void);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat(void);

        Brain &getBrain(void) const;
        void  makeSound(void) const;
};

#endif