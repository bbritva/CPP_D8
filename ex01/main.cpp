#include "Span.hpp"

# define SIZE 10

int main()
{
  Span span(SIZE);
  for (int i = 0; i < SIZE; ++i)
  {
    try
    {
      span.addNumber(i);
    }
    catch (Span::FullSpanException &e)
    {
      std::cerr << e.what();
    }
  }
  std::cout << span;

  try
  {
    std::cout << "Try to add number to full span:\n";
    span.addNumber(42);
  }
  catch (Span::FullSpanException &e)
  {
    std::cerr << e.what();
  }
}
