#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <stdint.h>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(): std::stack<T>(){}
	MutantStack(const MutantStack<T>& other): std::stack<T>(other){}
	MutantStack<T>& operator=(const MutantStack<T>& other)
	{
		if (this == &other)
			return (*this);
		std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack(){}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return std::stack<T>::c.begin();
	}
	iterator end()
	{
		return std::stack<T>::c.end();
	}
	
	typedef typename std::stack<T>::container_type::const_iterator 
	const_iterator;
	const_iterator cbegin()
	{
		return std::stack<T>::c.cbegin();
	}
	const_iterator cend()
	{
		return std::stack<T>::c.cend();
	}
	
	typedef typename std::stack<T>::container_type::reverse_iterator 
	reverse_iterator;
	reverse_iterator rbegin()
	{
		return std::stack<T>::c.rbegin();
	}
	reverse_iterator rend()
	{
		return std::stack<T>::c.rend();
	}
	
	typedef typename std::stack<T>::container_type::const_reverse_iterator 
	const_reverse_iterator;
	const_iterator crbegin()
	{
		return std::stack<T>::c.crbegin();
	}
	const_iterator crend()
	{
		return std::stack<T>::c.crend();
	}
};

template <typename T>
void showContainer(T& cont)
{
	typename T::iterator it;
	it = cont.begin();
	std::cout << "Container = {";
	for (; it != cont.end(); it++)
	{
		std::cout << *it;
		if ((++it) != cont.end())
			std::cout << ", ";
		it--;
	}
	std::cout << "}\n";
}
template <typename T>
void reversShowContainer(T& cont)
{
	typename T::reverse_iterator rit;
	rit = cont.rbegin();
	std::cout << "Container = {";
	for (; rit != cont.rend(); rit++)
	{
		std::cout << *rit;
		if ((++rit) != cont.rend())
			std::cout << ", ";
		rit--;
	}
	std::cout << "}\n";
}
#endif//MUTANTSTACK_HPP
