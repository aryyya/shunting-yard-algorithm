#pragma once

#include <string>
#include <ostream>

class Token
{
private:
  std::string symbols;

public:
  Token(const std::string& symbols);
  Token(const Token& token);
  const std::string& to_string() const;
};

std::ostream& operator<<(std::ostream& ostream, const Token& token);
