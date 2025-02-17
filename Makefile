CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lcurl -ljsoncpp

SRC = FakeRest.cpp client.cpp friend.cpp user.cpp city.cpp cities.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = FakeRest

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ) $(LDFLAGS)

# Rule to compile source files to object files
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

# Clean up the generated files
clean:
	rm -f $(OBJ) $(EXEC)

# Rule to run the server (optional, but helpful)
run: $(EXEC)
	./$(EXEC)
