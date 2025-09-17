/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:23:08 by claudia           #+#    #+#             */
/*   Updated: 2025/08/28 12:58:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain(void);
        Brain (Brain const &copy);
        Brain(std::string const &type);
        Brain &operator=(const Brain &copy);
        ~Brain();

        std::string const &getIdea(int const &index) const;
        void setIdea(std::string const &idea, int const &index);
};

#endif

