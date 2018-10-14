#include "Expression.hpp"
#include "Token.hpp"

#include <string>
#include <vector>
#include <sstream>

std::vector<Token> tokenize(const std::string& expression);

Expression::Expression(const std::string& expression)
{
  this->expression = expression;
  tokens = tokenize(expression);
}

std::string Expression::to_string() const
{
  std::string output = "";
  for (const Token& token : tokens)
  {
    output += token.to_string() + " ";
  }
  return output;
}

Expression Expression::to_postfix() const
{
  return Expression("");
}

double Expression::solve() const
{
  return 0.0;
}

std::vector<Token> tokenize(const std::string& expression)
{
  std::vector<Token> tokens;
  std::stringstream expression_stream(expression);
  while (expression_stream.good())
  {
    std::string token = "";
    expression_stream >> token;
    tokens.push_back(Token(token));
  }
  return tokens;
}
