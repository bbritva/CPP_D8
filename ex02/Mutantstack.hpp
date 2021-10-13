#ifndef MUTANTSTACK_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdint.h>

class Mutantstack
{
private:
  std::vector<int>  _arr;
  unsigned int      _len;
public:
  const std::vector<int> &getArr() const;

public:
  unsigned int getLen() const;

private:
  Mutantstack();

public:
  Mutantstack(unsigned int len);
  Mutantstack(Mutantstack const &other);
  Mutantstack &operator=(const Mutantstack &other);
  ~Mutantstack();

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

std::ostream& operator<<(std::ostream &stream, const Mutantstack &span);

#endif//MUTANTSTACK_HPP
