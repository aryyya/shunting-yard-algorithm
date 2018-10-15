#include "Number.hpp"

#include <cstdlib>

Number::Number(const Token& token) : Token(token)
{
  value = std::strtol(token.to_string().c_str(), nullptr, 10);
}

bool Number::is_number(const Token& token)
{
  char *end_ptr = nullptr;
  std::strtol(token.to_string().c_str(), &end_ptr, 10);
  return !(*end_ptr);
}
