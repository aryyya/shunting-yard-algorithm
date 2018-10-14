#include "ShuntingYard.hpp"
#include "Expression.hpp"
#include "Token.hpp"

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
  }

  return Expression(out_queue);
}
