#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <map>
# include <deque>
# include <set>
# include <queue>
# include <algorithm>

# define NOTHING_FOUND "\x1B[35mNothing found =(\n\x1B[0m"

template <typename T>
typename T::iterator easyfind(T& cont, int num)
{
	typename T::iterator it;
	it = find(cont.begin(), cont.end(), num);
	if (it == cont.end())
		throw std::exception();
	return (it);
}

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

#endif//EASYFIND_HPP
