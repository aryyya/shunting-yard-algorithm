#pragma once

#include <string>
#include <vector>

#include "Token.hpp"

class Expression
{
private:
  std::string expression;
  std::vector<Token> tokens;

public:
  Expression(const std::string& expression);
  std::string to_string() const;
  Expression to_postfix() const;
  double solve() const;
};
