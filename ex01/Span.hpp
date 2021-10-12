#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdint.h>

class Span
{
private:
  std::vector<int>  _arr;
  unsigned int      _len;
public:
  const std::vector<int> &getArr() const;

public:
  unsigned int getLen() const;

private:
  Span();

public:
  Span(unsigned int len);
  Span(Span const &other);
  Span &operator=(const Span &other);
  ~Span();

  void  addNumber(int);
  int   shortestSpan();
  int   longestSpan();


  class FullSpanException : public std::exception
  {
  public:
    const char* what() const throw();
  };

  class TooFewElementsException : public std::exception
  {
  public:
    const char* what() const throw();
  };

};

std::ostream& operator<<(std::ostream &stream, const Span &span);

#endif//SPAN_HPP
