#include <iostream>
#include <cstdlib>
#include <string>

void show_not_enough_arguments_error();
void show_help();
void show_version();
void parse_args(const int argc, char *argv[]);

int main(int argc, char *argv[])
{
  parse_args(argc, argv);

  const std::string expression = argv[1];
  std::cout << "Expression: " << expression << "\n";
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
