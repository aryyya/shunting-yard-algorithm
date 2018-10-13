all:
	c++ *.cpp -o sya -std=c++14

.PHONY: clean
clean:
	rm sya*
