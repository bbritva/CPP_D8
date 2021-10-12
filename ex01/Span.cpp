//
// Created by boris on 12.10.2021.
//

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
