#include "Token.hpp"

#include <string>

Token::Token(const std::string& symbols)
{
  this->symbols = symbols;
}

Token::Token(const Token& token)
{
  this->symbols = token.to_string();
}

const std::string& Token::to_string() const
{
  return symbols;
}

std::ostream& operator<<(std::ostream& ostream, const Token& token)
{
  return ostream << token.to_string();
}
