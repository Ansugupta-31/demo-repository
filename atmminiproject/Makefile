CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = atm
SRCS = main.cpp common.cpp admin.cpp filehandler.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) users.txt transactions.txt admin.txt blocked.txt

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
