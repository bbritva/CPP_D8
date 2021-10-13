#include "Mutantstack.hpp"

#define SIZE 5

int main()
{
	{
		std::cout << "\x1B[36m============SUBJECT TESTS============\x1B[0m\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\x1B[36m============MY INT TESTS============\x1B[0m\n";
		MutantStack<int> mstack;
		std::cout << "Push 0-4 to stack:\n";
		for (int i = 0; i < SIZE; ++i)
			mstack.push(i);
		showContainer(mstack);
		std::cout << "Top = " << mstack.top() << std::endl;
		std::cout << "Size = " << mstack.size() << std::endl;
		std::cout << "Pop from stack" << std::endl;
		mstack.pop();
		std::cout << "Top = " << mstack.top() << std::endl;
		std::cout << "Size = " << mstack.size() << std::endl;
		showContainer(mstack);
		MutantStack<int> mstack_copy(mstack);
		std::cout << "Stack copied, pushed 42 to origin.\nOrigin: ";
		mstack.push(42);
		showContainer(mstack);
		std::cout << "Copy: ";
		showContainer(mstack_copy);
		std::cout << "Revers show origin: ";
		reversShowContainer(mstack);
		std::stack<int> s(mstack);
	}
}
