#include "easyfind.hpp"

int main()
{
	std::vector<int> myVector;
	myVector.reserve(5);
	for (int count=0; count < 5; ++count)
		myVector.push_back(count);
	std::vector<int>::iterator it;
	it = myVector.begin();
	std::cout << "myVector = {";
	for (; it != myVector.end(); it++)
		std::cout << *it << ", ";
	std::cout << "}\n";
	try
	{
		it = easyfind(myVector, 2);
		std::cout << *it << "\n";
		*it = 42;
		it = myVector.begin();
		std::cout << "myVector = {";
		for (; it != myVector.end(); it++)
			std::cout << *it << ", ";
		std::cout << "}\n";
	}
	catch (std::exception&)
	{
		std::cerr << "Nothing found\n";
	}
}
