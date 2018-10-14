#include "ShuntingYard.hpp"
#include "Expression.hpp"
#include "Token.hpp"
#include "Operator.hpp"

#include <iostream>
#include <stack>
#include <queue>

void handle_operator(const Operator&, std::queue<Token>&, std::stack<Operator>&);
void handle_opening_bracket(const Operator&, std::queue<Token>&, std::stack<Operator>&);
void handle_closing_bracket(const Operator&, std::queue<Token>&, std::stack<Operator>&);
void handle_number(const Operator&, std::queue<Token>&, std::stack<Operator>&);

void handle_operator(
  const Operator& operator_,
  std::queue<Token>& output_queue,
  std::stack<Operator>& operator_stack)
{
  if (operator_.is_opening_bracket())
  {
    handle_opening_bracket(operator_, output_queue, operator_stack);
  }

  else if (operator_.is_closing_bracket())
  {
    handle_closing_bracket(operator_, output_queue, operator_stack);
  }

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
}

void handle_opening_bracket(
  const Operator& opening_bracket,
  std::queue<Token>& output_queue,
  std::stack<Operator>& operator_stack)
{
  operator_stack.push(opening_bracket);
}

void handle_closing_bracket(
  const Operator& closing_bracket,
  std::queue<Token>& output_queue,
  std::stack<Operator>& operator_stack)
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

Expression shunting_yard(const Expression& expression)
{
  std::queue<Token> output_queue;
  std::stack<Operator> operator_stack;

  for (const Token& token : expression.get_tokens())
  {
    if (token.is_number())
    {
    }

    else if (Operator::is_operator(token))
    {
      handle_operator(token, output_queue, operator_stack);
    }
  }

  while (!operator_stack.empty())
  {
    output_queue.push(operator_stack.top());
    operator_stack.pop();
  }

  return Expression(output_queue);
}
