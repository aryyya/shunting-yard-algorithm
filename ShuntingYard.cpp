#include "ShuntingYard.hpp"
#include "Expression.hpp"
#include "Token.hpp"
#include "Operator.hpp"

#include <iostream>
#include <stack>
#include <queue>

Expression shunting_yard(const Expression expression)
{
  std::queue<Token> out_queue;
  std::stack<Token> opr_stack;

  for (const Token& token : expression.get_tokens())
  {
    out_queue.push(token);

    if (token.is_number())
    {
      std::cout << token.to_string() << " is a number\n";
    }

    else if (Operator::is_operator(token))
    {
      std::cout << token.to_string() << " is an operator\n";
    }

    else if (token.is_opening_bracket())
    {
      std::cout << token.to_string() << " is a left bracket\n";
    }

    else if (token.is_closing_bracket())
    {
      std::cout << token.to_string() << " is a right bracket\n";
    }
  }

  return Expression(out_queue);
}
