#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "error: not enough arguments\n";
    std::cerr << "usage: sya [expression]\n";
    std::exit(-1);
  }

  const std::string expression = argv[1];
  std::cout << "expression: " << expression << "\n";
}
