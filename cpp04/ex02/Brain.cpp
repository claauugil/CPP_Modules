/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:23:57 by claudia           #+#    #+#             */
/*   Updated: 2025/08/21 17:06:36 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << CYAN << "Brain has been constructed with default constructor!" << RESET << std::endl;
}

Brain::Brain(Brain const &copy)
{
    *this = copy;
    std::cout << "Brain copied." << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
    }   
    std::cout << "Assignment operator for Brain called." << std::endl;
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << RED << "Brain destroyed" << RESET << std::endl;
}

std::string const &Brain::getIdea(int const &index) const
{
    if (index >= 0 && index < 100)
        return (this->_ideas[index]);
    return (this->_ideas[0]); // avoid crashing since it returns a valid address
}

void Brain::setIdea(std::string const &idea, int const &index)
{
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
}