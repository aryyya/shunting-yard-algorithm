#pragma once

#include "Token.hpp"

enum class OperatorAssociativity
{
  left,
  right
};

struct OperatorCharacteristics
{
  std::string symbol;
  std::string name;
  int precedence;
  OperatorAssociativity associativity;
};

class Operator : public Token
{
private:
  OperatorCharacteristics characteristics;

public:
  Operator(const Token& token);
  static bool is_operator(const Token& token);
  bool is_left_associative() const;
  bool is_right_associative() const;
  int get_precedence() const;
  bool is_left_bracket() const;
  bool is_right_bracket() const;
};

bool operator==(const Operator& operator1, const Operator& operator2);
bool operator<(const Operator& operator1, const Operator& operator2);
bool operator>(const Operator& operator1, const Operator& operator2);
