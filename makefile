CXX = g++
CXXFLAGS = -I./include

SOURCES = src/publish.cpp src/subscribe.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = publish-subscribe

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
