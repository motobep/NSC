SRC = ./src/
BIN = ./bin/
TARGET = nsc-dev
TARGET_PROD = nsc
TEST = test/hello.nscp
FLAGS = -std=c++17 -o

all: prod

do: build run

run:
		$(BIN)$(TARGET) $(TEST)

run-prod:
		$(BIN)$(TARGET_PROD) $(TEST)

build:
		g++ $(SRC)*.cpp $(FLAGS) $(BIN)$(TARGET)

prod:
		g++ $(SRC)*.cpp -O3 $(FLAGS) $(BIN)$(TARGET_PROD)
