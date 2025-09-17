/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:49:01 by claudia           #+#    #+#             */
/*   Updated: 2025/08/29 16:53:04 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const int NBR_OF_ANIMALS = 4;
    Animal *animals[NBR_OF_ANIMALS];

    for (int i = 0; i < NBR_OF_ANIMALS; i++)
    {
        if (i < NBR_OF_ANIMALS / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < NBR_OF_ANIMALS; i++)
        animals[i]->makeSound();
    std::cout << "\n------- Testing deep copy ------\n" << std::endl;
    std::cout << "-------------------------------------\n";
	std::cout << animals[0]->getType() << std::endl;
	std::cout << animals[2]->getType() << std::endl;
	Brain *brain;
	brain = &animals[0]->getBrain();
	brain->setIdea("I want food!", 0);
	brain->setIdea("Let's play!!", 1);
	brain->setIdea("Feed me!", 2);
	std::cout << animals[0]->getBrain().getIdea(0) << std::endl;
	std::cout << animals[0]->getBrain().getIdea(1) << std::endl;
	std::cout << animals[0]->getBrain().getIdea(2) << std::endl;
	std::cout << "-------------------------------------\n";
	for (int i = 0; i < NBR_OF_ANIMALS; i++)
		delete animals[i];
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
	}
	return (0);
}