#include "Operator.hpp"

#include <map>
#include <stdexcept>

const std::map<
  const std::string,
  const OperatorCharacteristics
> operators = {
  {
    "+", {
      symbol: "+",
      name: "addition",
      precedence: 2,
      associativity: OperatorAssociativity::left
    },
  },
  {
    "-", {
      symbol: "-",
      name: "subtraction",
      precedence: 2,
      associativity: OperatorAssociativity::left
    },
  },
  {
    "*", {
      symbol: "*",
      name: "multiplication",
      precedence: 3,
      associativity: OperatorAssociativity::left
    },
  },
  {
    "/", {
      symbol: "/",
      name: "division",
      precedence: 3,
      associativity: OperatorAssociativity::left
    },
  },
  {
    "^", {
      symbol: "^",
      name: "exponentiation",
      precedence: 4,
      associativity: OperatorAssociativity::right
    },
  }
};

Operator::Operator(const Token& token)
{
  characteristics = operators.at(token.to_string());
}

bool Operator::is_operator(const Token& token)
{
  try
  {
    operators.at(token.to_string());
    return true;
  }
  catch (const std::out_of_range& exception)
  {
    return false;
  }
}

bool Operator::is_left_associative() const
{
  return characteristics.associativity == OperatorAssociativity::left;
}

bool Operator::is_right_associative() const
{
  return characteristics.associativity == OperatorAssociativity::right;
}

int Operator::get_precedence() const
{
  return characteristics.precedence;
}
