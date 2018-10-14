#pragma once

#include <string>
#include <vector>

#include "Token.hpp"

class Expression
{
private:
  std::vector<Token> tokens;

public:
  Expression(const std::string& expression);
  std::string to_string() const;
  Expression to_postfix() const;
  double solve() const;
  int get_tokens_length() const;
  const Token& get_token(const int index) const;
};
