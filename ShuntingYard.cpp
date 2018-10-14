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
    std::cout << "\n" << token.to_string() << "\n";
    output_queue.push(token);

    if (token.is_number())
    {
    }

    else if (Operator::is_operator(token))
    {
      const Operator operator_(token);
      if (!operator_stack.empty())
      {
        Operator stack_operator = operator_stack.top();
        while (!operator_stack.empty()
           && (stack_operator > operator_
           || ((stack_operator == operator_ && stack_operator.is_left_associative())
           && (!stack_operator.is_left_bracket()))))
        {
          output_queue.push(stack_operator);
          operator_stack.pop();
        }
      }
      operator_stack.push(operator_);

      if (operator_.is_opening_bracket())
      {
        operator_stack.push(operator_);
      }

      else if (operator_.is_closing_bracket())
      {
        if (!operator_stack.empty())
        {
          Operator stack_operator = operator_stack.top();
          while (!operator_stack.empty()
              && !stack_operator.is_opening_bracket())
          {
            output_queue.push(stack_operator);
            operator_stack.pop();
            if (!operator_stack.empty())
            {
              stack_operator = operator_stack.top();
            }
          }
          if (!operator_stack.empty())
          {
            operator_stack.pop();
          }
        }
      }
    }
  }

  while (!operator_stack.empty())
  {
    output_queue.push(operator_stack.top());
    operator_stack.pop();
  }

  return Expression(output_queue);
}
