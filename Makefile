# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

# Source files
SOURCES = test_network.cpp network.cpp misc.cpp date.cpp person.cpp contact.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXEC = test_network

# Rules

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXEC)

.PHONY: all clean