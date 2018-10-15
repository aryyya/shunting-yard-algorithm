#include "Expression.hpp"
#include "Token.hpp"
#include "ShuntingYard.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <queue>

std::vector<Token> tokenize(const std::string& expression);

Expression::Expression(const std::string& expression)
{
  tokens = tokenize(expression);
}

Expression::Expression(std::queue<Token>& expression)
{
  std::string expression_string = "";
  while (!expression.empty())
  {
    const Token token = expression.front();
    expression.pop();
    expression_string += token.to_string() + " ";
  }
  tokens = tokenize(expression_string);
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
  return shunting_yard(to_string());
}

double Expression::solve() const
{
  return 0.0;
}

const std::vector<Token>& Expression::get_tokens() const
{
  return tokens;
}

std::vector<Token> tokenize(const std::string& expression)
{
  std::vector<Token> tokens;
  std::stringstream expression_stream(expression);
  while (expression_stream.good())
  {
    std::string token = "";
    expression_stream >> token;
    if (token.length() > 0)
    {
      tokens.push_back(token);
    }
  }
  return tokens;
}

std::ostream& operator<<(std::ostream& ostream, const Expression& expression)
{
  return ostream << expression.to_string();
}
