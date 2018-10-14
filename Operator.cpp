#include "Operator.hpp"

#include <map>

struct OperatorCharacteristics
{
  std::string symbol;
  int precedence;
};

std::map<std::string, OperatorCharacteristics> operators = {
  {
    "+",
    {
      "+",
      4
    }
  }
};

Operator::Operator()
{

}

bool is_operator(const Token& token)
{
  return false;
}
