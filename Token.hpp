#pragma once

#include <string>

class Token
{
private:
  std::string symbols;

public:
  Token(const std::string& symbols);
  Token(const Token& token);
  const std::string& to_string() const;
  bool is_operator() const;
  bool is_number() const;
  bool is_opening_bracket() const;
  bool is_closing_bracket() const;
};
