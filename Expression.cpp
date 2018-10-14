#include "Expression.hpp"
#include "Token.hpp"
#include "ShuntingYard.hpp"

#include <string>
#include <vector>
#include <sstream>

std::vector<Token> tokenize(const std::string& expression);

Expression::Expression(const std::string& expression)
{
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
  return shunting_yard(Expression(to_string()));
}

double Expression::solve() const
{
  return 0.0;
}

int Expression::get_tokens_length() const
{
  return tokens.size();
}

const Token& Expression::get_token(const int index) const
{
  return tokens[index];
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
