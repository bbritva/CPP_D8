//
// Created by boris on 12.10.2021.
//

#include <cmath>
#include "Span.hpp"

Span::Span(): _len(0){}

Span::Span(unsigned int len): _len(len)
{
  _arr.reserve(len);
}

Span::Span(const Span &other): _len(other._len)
{
  for (unsigned int i = 0; i < _len; i++)
    _arr.push_back(other._arr[i]);
}

Span &Span::operator=(const Span &other)
{
  if (this == &other)
    return (*this);
  _len = other._len;
  for (unsigned int i = 0; i < _len; i++)
    _arr.push_back(other._arr[i]);
  return (*this);
}

Span::~Span(){}

void Span::addNumber(int num)
{
  if (_arr.size() == _len)
    throw FullSpanException();
  _arr.push_back(num);
}

unsigned int Span::getLen() const
{
  return _len;
}

const std::vector<int> &Span::getArr() const
{
  return _arr;
}

int Span::shortestSpan()
{
  if (_len < 2 || _arr.size() < 2)
    throw TooFewElementsException();
  int res = INT32_MAX;
  std::vector<int>::iterator it = _arr.begin();
  std::vector<int>::iterator it2;
  for (; it != _arr.end() ; ++it)
  {
    it2 = _arr.begin();
    for (; it2 != _arr.end() ; ++it2)
      if (it != it2 && (abs(*it - *it2) < res))
        res = abs(*it - *it2);
  }
  return res;
}

int Span::longestSpan()
{
  if (_len < 2 || _arr.size() < 2)
    throw TooFewElementsException();
  int res = 0;
  std::vector<int>::iterator it = _arr.begin();
  std::vector<int>::iterator it2;
  for (; it != _arr.end() ; ++it)
  {
    it2 = _arr.begin();
    for (; it2 != _arr.end() ; ++it2)
      if (it != it2 && (abs(*it - *it2) > res))
        res = abs(*it - *it2);
  }
  return res;
}

std::ostream& operator<<(std::ostream &stream, const Span &span)
{
  stream << "This span size = " << span.getLen() << ", and looks like:\n{";
  for (unsigned int i = 0; i < span.getLen(); ++i)
  {
    stream << span.getArr()[i];
    if (i != span.getLen() - 1)
      stream << ", ";
  }
  stream << "}\n";
  return stream;
}

const char *Span::FullSpanException::what() const throw()
{
  return ("\x1B[35mexception: Span is full.\n\x1B[0m");
}

const char *Span::TooFewElementsException::what() const throw()
{
  return ("\x1B[35mexception: Too few elements.\n\x1B[0m");
}
