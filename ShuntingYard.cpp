#include "ShuntingYard.hpp"
#include "Expression.hpp"
#include "Token.hpp"
#include "Operator.hpp"

#include <iostream>
#include <stack>
#include <queue>

Expression shunting_yard(const Expression expression)
{
  std::queue<Token> output_queue;
  std::stack<Operator> operator_stack;

  for (const Token& token : expression.get_tokens())
  {
    output_queue.push(token);

    if (token.is_number())
    {
      std::cout << token.to_string() << " is a number\n";
    }

    else if (Operator::is_operator(token))
    {
      const Operator operator_(token);
      if (!operator_stack.empty())
      {
        const Operator stack_operator = operator_stack.top();
        while (stack_operator > operator_
           || ((stack_operator == operator_ && stack_operator.is_left_associative())
           && (!stack_operator.is_left_bracket())))
        {
          output_queue.push(stack_operator);
          operator_stack.pop();
        }
      }
      operator_stack.push(operator_);
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

  return Expression(output_queue);
}
