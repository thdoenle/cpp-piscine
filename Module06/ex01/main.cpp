#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data data = {42, -42, 21.21};

	uintptr_t rawDataPtr;
	Data * dataPtr;

	rawDataPtr = Serializer::serialize(&data);
	dataPtr = Serializer::deserialize(rawDataPtr);

	std::cout << dataPtr->l << " " << dataPtr->i
		<< " " << dataPtr->d << std::endl;
}