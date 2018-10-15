#include <iostream>
#include <cstdlib>
#include <string>

#include "Expression.hpp"

void show_not_enough_arguments_error();
void show_help();
void show_version();
void parse_args(const int argc, char *argv[]);

int main(int argc, char *argv[])
{
  parse_args(argc, argv);

  Expression expression(argv[1]);
  Expression expression_postfix = expression.to_postfix();

  std::cout << expression_postfix << "\n";
}

void show_not_enough_arguments_error()
{
  std::cerr
    << "Error: Not enough arguments.\n"
    << "Try `sya --help` for usage instructions.\n"
    << "\n";
  std::exit(-1);
}

void show_help()
{
  std::cout
    << "sya - An implementation of the Shunting Yard algorithm.\n"
    << "\n"
    << "Usage:\n"
    << "  sya [expression]\n"
    << "\n"
    << "Mandatory Arguments:\n"
    << "  expression    A quoted mathematical expression.\n"
    << "\n"
    << "Options:\n"
    << " -h, --help:    Show this help screen.\n"
    << " -v, --version: Show the version.\n"
    << "\n"
    << "Supported Operators:\n"
    << " + Add\n"
    << " - Subtract\n"
    << " * Multiply\n"
    << " / Divide\n"
    << " ^ Exponent\n"
    << " ( Left Bracket\n"
    << " ) Right Bracket\n"
    << "\n"
    << "Example:\n"
    << "  sya '1 + 2 * ( 3 / 4 ) ^ 5'\n"
    << "\n";
  std::exit(0);
}

void show_version()
{
  std::cout << "Version: 1.0.0\n";
  std::exit(0);
}

void parse_args(const int argc, char *argv[])
{
  if (argc < 2)
  {
    show_not_enough_arguments_error();
  }

  for (int i = 0; i < argc; i++)
  {
    std::string arg = argv[i];
    if (arg == "--help" || arg == "-h")
    {
      show_help();
    }
    else if (arg == "--version" || arg == "-v")
    {
      show_version();
    }
  }
}
