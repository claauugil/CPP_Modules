/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:51:34 by cgil              #+#    #+#             */
/*   Updated: 2026/01/14 17:21:31 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

/* Function that finds the first ocurrence of the second
   parameter in the first parameter. 
   Returns an iterator that points to the found element, not the element itself.
*/
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}
#endif
