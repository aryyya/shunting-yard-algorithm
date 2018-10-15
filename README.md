# shunting-yard-algorithm

An implementation of the [Shunting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm) in C++.

Currently it can be used to convert a mathematical expression from infix notation to postfix notation. More features to come.

## Build

```bash
make
```

## Usage

```
sya - An implementation of the Shunting Yard algorithm.

Usage:
  sya [expression]

Mandatory Arguments:
  expression                  A quoted mathematical expression.

Options:
 -h, --help                   Show this help screen.
 -v, --version                Show the version.

Supported Operators:
 +                            Add.
 -                            Subtract.
 *                            Multiply.
 /                            Divide.
 ^                            Exponent.
 (                            Left Bracket.
 )                            Right Bracket.

Example:
  sya '1 + 2 * ( 3 / 4 ) ^ 5'
```

## Roadmap

- [x] Expression abstraction.
- [x] Token abstraction.
- [x] Operator abstraction as subclass of Token.
- [x] Number abstraction as subclass of Token.
- [x] Shunting Yard infix to postfix conversion.
- [ ] Input sanitization and error handler.
- [ ] Postfix expression solver.
- [ ] Interactive mode.
