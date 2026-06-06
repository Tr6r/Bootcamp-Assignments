CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = main.cpp shell.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)