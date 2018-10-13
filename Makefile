all:
	c++ -Wextra -Wall -std=c++14 *.cpp -o sya

.PHONY: clean
clean:
	rm sya*
