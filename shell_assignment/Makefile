CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# App
TARGET = shell
OBJ = main.o shell.o
app: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Unit test
TEST_TARGET = test_shell
TEST_OBJ = test/test_shell.o shell.o
GTEST_FLAGS = -lgtest -lgtest_main -pthread
test: $(TEST_TARGET)
	./$(TEST_TARGET)
$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(TEST_OBJ) $(GTEST_FLAGS) -o $(TEST_TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o test/*.o $(TARGET) $(TEST_TARGET)