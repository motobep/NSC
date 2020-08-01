SRC = ./src/
BIN = ./bin/
TARGET = nsc-dev
TARGET_PROD = nsc
FLAGS = -std=c++17 -o

all: build

do: build run

run:
		$(BIN)$(TARGET) test/hello.nsc

run-prod:
		$(BIN)$(TARGET_PROD) test/hello.nsc

build:
		g++ $(SRC)*.cpp $(FLAGS) $(BIN)$(TARGET)

prod:
		g++ $(SRC)*.cpp -O3 $(FLAGS) $(BIN)$(TARGET_PROD)
