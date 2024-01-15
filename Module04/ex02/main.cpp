#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const AAnimal* d = new Dog();
		const AAnimal* c = new Cat();

		delete d;
		delete c;
	}

	std::cout << std::endl << "============" << std::endl << std::endl;

	{
		Cat a;
		Cat b;

		a.addIdea("croquette");
		b = a;
		b.addIdea("miam");
		b.addIdea("ROnronn");
		a.tellIdeas();
		b.tellIdeas();

		Cat testCopy = b;
		{
			Cat test = testCopy;
			test.addIdea("G faim");
			test.tellIdeas();
		}
		testCopy.tellIdeas();
	}

	std::cout << std::endl << "============" << std::endl << std::endl;

	{
		AAnimal ** tab = new AAnimal * [8];
		
		Dog dogBase;
		Cat catBase;

		std::cout << "--- CREATE DOGS ---" << std::endl;
		for (int i = 0; i < 4; i++)
			tab[i] = new Dog(dogBase);
		std::cout << "--- CREATE CATS ---" << std::endl;
		for (int i = 4; i < 8; i++)
			tab[i] = new Cat(catBase);

		std::cout << "--- PRINT TYPES ---" << std::endl;
		for (int i = 0; i < 8; i++)
			std::cout << i << " -> " << tab[i]->getType() << std::endl;
		
		std::cout << "--- DELETE TAB ---" << std::endl;
		for (int i = 0; i < 8; i++)
			delete tab[i];
		delete [] tab;
	}

	// AAnimal test; // <- ERROR
}