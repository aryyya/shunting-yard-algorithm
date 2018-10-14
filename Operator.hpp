#pragma once

#include "Token.hpp"

class Operator
{
private:

public:
  Operator();
  static bool is_operator(const Token& token);
};
