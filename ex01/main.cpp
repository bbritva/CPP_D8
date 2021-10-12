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
    std::cout << "Try to add number into full span:\n";
    span.addNumber(42);
  }
  catch (Span::FullSpanException &e)
  {
    std::cerr << e.what();
  }
  std::cout << "longest = " << span.longestSpan() << "\n";
  std::cout << "shortest = " << span.shortestSpan() << "\n";

  Span span1(1);
  span1.addNumber(3);
  try
  {
    std::cout << "Try to find shortest span in too small array:\n";
    int res = span1.shortestSpan();
    std::cout << "shortest = " << res << "\n";
  }
  catch (Span::TooFewElementsException &e)
  {
    std::cerr << e.what();
  }
  try
  {
    std::cout << "Try to find longest span in too small array:\n";
    int res = span1.longestSpan();
    std::cout << "longest = " << res << "\n";
  }
  catch (Span::TooFewElementsException &e)
  {
    std::cerr << e.what();
  }
}
