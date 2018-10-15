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

  std::cout << "ifix: " << expression.to_string() << "\n";
  std::cout << "pfix: " << expression_postfix.to_string() << "\n";
}

void show_not_enough_arguments_error()
{
  std::cerr << "Error: Not enough arguments.\n";
  std::cerr << "Try `sya --help` for usage instructions.\n";
  std::exit(-1);
}

void show_help()
{
  std::cout
    << "Usage: sya [Expression]\n"
    << "Option Flags:\n"
    << " -h, --help:    Show this help screen.\n"
    << " -v, --version: Show the version.\n"
    << "Supported Operators:\n"
    << " + Add\n"
    << " - Subtract\n"
    << " * Multiply\n"
    << " / Divide\n"
    << " ^ Exponent\n"
    << " ( Left Bracket\n"
    << " ) Right Bracket\n";
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
