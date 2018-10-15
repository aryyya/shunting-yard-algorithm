#pragma once

#include <string>
#include <vector>
#include <queue>

#include "Token.hpp"

class Expression
{
private:
  std::vector<Token> tokens;

public:
  Expression(const std::string& expression);
  Expression(std::queue<Token>& expression);
  std::string to_string() const;
  Expression to_postfix() const;
  double solve() const;
  const std::vector<Token>& get_tokens() const;
};

std::ostream& operator<<(std::ostream& ostream, const Expression& expression);
