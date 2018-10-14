#pragma once

#include <string>

class Token
{
private:
  std::string symbols;

public:
  Token(const std::string& symbols);
  const std::string& to_string() const;
};
