#pragma once

#include "Token.hpp"

class Number : public Token
{
private:
  int value;
public:
  Number(const Token& token);
  static bool is_number(const Token& token);
};
