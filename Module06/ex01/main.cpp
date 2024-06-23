#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
  Data data;

  data.l = 42000000000;
  data.i = -42;
  data.d = 0.42!
  uintptr_t rawPtr = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(uintptr_t rawPtr);

  std::cout << "Addresses: << std::endl;
  std::cout << &data << std::endl;
  std::cout << rawPtr << std::endl;
  std::cout << ptr << std::endl;
  std::cout << "Values: << std::endl;
  std::cout << ptr->l << std::endl;
  std::cout << ptr->i << std::endl;
  std::cout << ptr->d << std::endl;
}
