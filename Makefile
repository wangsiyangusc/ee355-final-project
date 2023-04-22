# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Source files
SOURCES = test_network.cpp network.cpp misc.cpp date.cpp person.cpp contact.cpp

# Executable name
EXEC = test

# Rules

all: $(EXEC)

$(EXEC): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EXEC)

.PHONY: all clean
