#include "easyfind.hpp"

int main()
{
  //тесты вектора
  std::cout << "\x1B[36m=================================VECTOR TESTS=================================\x1B[0m\n";
  {
    std::vector<int> myVector;
    myVector.reserve(5);
    for (int count = 0; count < 5; ++count)
      myVector.push_back(count);
    std::vector<int>::iterator it;
    showContainer(myVector);
    try
    {
      std::cout << "try to find 2:\n";
      it = easyfind(myVector, 2);
      std::cout << "Found value = " << *it << "\n";
      std::cout << "Replace found value by 42.\n";
      *it = 42;
      showContainer(myVector);
    }
    catch (std::exception &)
    {
      std::cerr << "Nothing found\n";
    }
    try
    {
      std::cout << "try to find 52:\n";
      it = easyfind(myVector, 2);
      std::cout << "Found value = " << *it << "\n";
      std::cout << "Replace found value by 42.\n";
      *it = 42;
      showContainer(myVector);
    }
    catch (std::exception &)
    {
      std::cerr << "Nothing found\n";
    }
  }
  std::cout << "\x1B[36m==================================LIST TESTS==================================\x1B[0m\n";
  {
    std::list<int> myList;
    for (int count = 0; count < 5; ++count)
      myList.push_back(count);
    std::list<int>::iterator it;
    showContainer(myList);
    try
    {
      std::cout << "try to find 2:\n";
      it = easyfind(myList, 2);
      std::cout << "Found value = " << *it << "\n";
      std::cout << "Replace found value by 42.\n";
      *it = 42;
      showContainer(myList);
    }
    catch (std::exception &)
    {
      std::cerr << "Nothing found\n";
    }
    try
    {
      std::cout << "try to find 52:\n";
      it = easyfind(myList, 2);
      std::cout << "Found value = " << *it << "\n";
      std::cout << "Replace found value by 42.\n";
      *it = 42;
      showContainer(myList);
    }
    catch (std::exception &)
    {
      std::cerr << "Nothing found\n";
    }
  }

}
