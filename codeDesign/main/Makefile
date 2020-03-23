CC = gcc
CXX = g++


SRC = ../src
SRC += .


CFLAGS = -c -Wall
CFLAGS += -g
CFLAGS += -fpic -lpthread
CFLAGS += -I$(SRC)
CFLAGS += -I$(COMMON)
CFLAGS += -std=c++11

CXXFLAGS = $(CFLAGS)



SOURCES = $(wildcard $(SRC)/*.cpp)

HEADS = $(wildcard $(SRC)/*.h)

OBJS = $(SOURCES:.cpp=.o)
TARGET = hello-cgi

all:$(TARGET)
$(TARGET):$(OBJS) $(SOURCES) $(HEADS)
	$(CXX)  -o $@ $(OBJS) $(LFLAGS) $(LDFLAGS)

$(OBJS):%.o:%.cpp $(HEADS)
	$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm -f echo core



.PHONY: all clean
