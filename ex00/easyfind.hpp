#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <map>
# include <deque>
# include <list>
# include <set>
# include <stack>
# include <queue>
# include <algorithm>

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
    std::cout << *it << ", ";
  std::cout << "}\n";
}

#endif//EASYFIND_HPP
