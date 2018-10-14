#include "Token.hpp"

#include <string>

Token::Token(const std::string& symbols)
{
  this->symbols = symbols;
}

const std::string& Token::to_string() const
{
  return symbols;
}
