all: run

run: build
	./build

CPP_COMP = g++-11
CPP_COMP_ARGS = -Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow -Woverloaded-virtual -pedantic
CPP_STD = -std=c++17

build: $(wildcard *.cpp *.h Makefile)
	$(CPP_COMP) $(CPP_STD) $(CPP_COMP_ARGS) *.cpp -o build

clean:
	rm -rf build
