/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:40:40 by claudia           #+#    #+#             */
/*   Updated: 2025/08/28 13:02:05 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
class Brain;

# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE   "\033[1;34m"
# define CYAN   "\033[1;36m"
# define RESET  "\033[0m"
# define RED	"\033[1;31m"

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal(void);
        AAnimal(std::string const &type);
        AAnimal(const AAnimal &copy);
        AAnimal &operator=(const AAnimal &copy);
        virtual ~AAnimal(void);
        
        std::string const   &getType(void) const;
        void                setType(std::string const &type);
        virtual Brain       &getBrain(void) const = 0;
        virtual void        makeSound(void)const = 0;
};

#endif
