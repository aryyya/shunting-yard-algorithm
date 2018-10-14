#include "Expression.hpp"
#include "Token.hpp"

#include <string>
#include <vector>

std::vector<Token> tokenize(const std::string& expression);

Expression::Expression(const std::string& expression)
{
  this->expression = expression;
  tokens = tokenize(expression);
}

const std::string Expression::to_string() const
{
  std::string output = "";
  for (const Token& token : tokens)
  {
    output += token.to_string() + " ";
  }
  return output;
}

std::vector<Token> tokenize(const std::string& expression)
{
  std::vector<Token> tokens;

  return tokens;
}
