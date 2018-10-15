#include "ShuntingYard.hpp"
#include "Expression.hpp"
#include "Token.hpp"
#include "Operator.hpp"
#include "Number.hpp"

#include <iostream>
#include <stack>
#include <queue>

void handle_number(const Number&, std::queue<Token>&);
void handle_operator(const Operator&, std::queue<Token>&, std::stack<Operator>&);
void handle_opening_bracket(const Operator&, std::stack<Operator>&);
void handle_closing_bracket(std::queue<Token>&, std::stack<Operator>&);
void print_output_queue(const std::queue<Token>&);
void print_operator_stack(const std::stack<Operator>&);

Expression shunting_yard(const Expression& expression)
{
  std::queue<Token> output_queue;
  std::stack<Operator> operator_stack;

  for (const Token& token : expression.get_tokens())
  {
    if (Number::is_number(token))
    {
      handle_number(token, output_queue);
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

  return output_queue;
}

void handle_number(
  const Number& number,
  std::queue<Token>& output_queue)
{
  output_queue.push(number);
}

void handle_operator(
  const Operator& operator_,
  std::queue<Token>& output_queue,
  std::stack<Operator>& operator_stack)
{
  const bool operator_is_opening_bracket = operator_.is_opening_bracket();
  const bool operator_is_closing_bracket = operator_.is_closing_bracket();

  if (!operator_is_opening_bracket && !operator_is_closing_bracket)
  {
    if (!operator_stack.empty())
    {
      Operator stack_operator = operator_stack.top();
      while (!operator_stack.empty()
          && (stack_operator > operator_
          || ((stack_operator == operator_ && stack_operator.is_left_associative())
          && !stack_operator.is_opening_bracket())))
      {
        output_queue.push(stack_operator);
        operator_stack.pop();
        if (!operator_stack.empty())
        {
          stack_operator = operator_stack.top();
        }
      }
    }
    operator_stack.push(operator_);
  }

  else if (operator_is_opening_bracket)
  {
    handle_opening_bracket(operator_, operator_stack);
  }

  else if (operator_is_closing_bracket)
  {
    handle_closing_bracket(output_queue, operator_stack);
  }
}

void handle_opening_bracket(
  const Operator& opening_bracket,
  std::stack<Operator>& operator_stack)
{
  operator_stack.push(opening_bracket);
}

void handle_closing_bracket(
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

void print_output_queue(const std::queue<Token>& output_queue)
{
  std::cout << "output queue: ";
  std::queue<Token> output_queue_copy = output_queue;
  while (!output_queue_copy.empty())
  {
    std::cout << output_queue_copy.front().to_string() << " ";
    output_queue_copy.pop();
  }
  std::cout << "\n";
}

void print_operator_stack(const std::stack<Operator>& operator_stack)
{
  std::cout << "operator stack: ";
  std::stack<Operator> operator_stack_copy = operator_stack;
  while (!operator_stack_copy.empty())
  {
    std::cout << operator_stack_copy.top().to_string() << " ";
    operator_stack_copy.pop();
  }
  std::cout << "\n";
}
