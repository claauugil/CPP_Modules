/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:10:59 by claudia           #+#    #+#             */
/*   Updated: 2025/07/07 17:49:31 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H
#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define LIGHT_BLUE "\001\033[1;94m\002"
# define PINK "\001\033[1;95m\002"
# define GREEN "\001\033[1;92m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);  
};

#endif