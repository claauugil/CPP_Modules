/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:06:22 by cgil              #+#    #+#             */
/*   Updated: 2026/01/26 16:25:42 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
   if (argc < 2)
   {
      std::cerr << RED<< "Error: no input numbers" << RESET << std::endl;
      return (1);
   }
   try
   {
      PmergeMe sorter;
      sorter.parseInput(argc, argv);
      sorter.sortAndPrint();
   }
   catch (std::exception &e)
   {
      std::cerr << e.what() << std::endl;
      return 1;  
   }
   return 0;
}