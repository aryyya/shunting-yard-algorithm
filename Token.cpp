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

bool Token::is_operator() const
{
  return
       symbols == "+"
    || symbols == "-"
    || symbols == "*"
    || symbols == "/"
    || symbols == "^";
}

bool Token::is_number() const
{
  return false;
}

bool Token::is_opening_bracket() const
{
  return symbols == "(";
}

bool Token::is_closing_bracket() const
{
  return symbols == ")";
}
