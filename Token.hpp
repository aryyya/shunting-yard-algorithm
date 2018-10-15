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
};
