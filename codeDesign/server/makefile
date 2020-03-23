CC = gcc
CXX = g++

COMM_DIR = ../cgi_frame/comm
#FRAME_DIR=../cgi_frame
#DATABASE_DIR = ../CSLPlatMng_device/src/cgi_frame/database
#INC_DIR = api/include
#LIB_DIR = api/lib64
MAIN_DIR = .
INCLUDE = ../include
RAPIDJSON = ../include/rapidjson





CFLAGS = -c -Wall
CFLAGS += -g
CFLAGS += -std=c++11

CFLAGS += -fpic -lpthread




CFLAGS += -I$(INCLUDE)
CFLAGS += -I$(MAIN_DIR)
CFLAGS += -I$(RAPIDJSON)
CXXFLAGS = $(CFLAGS)






HEADS += $(wildcard $(MAIN_DIR)/*.h)


SOURCES += $(wildcard $(MAIN_DIR)/*.cpp)

OBJS = $(SOURCES:.cpp=.o)
TARGET = TEST_JWT


LDFLAGS = -Wl,-R /usr/local/lib

all:$(TARGET)
$(TARGET):$(OBJS) $(SOURCES) $(HEADS)
	$(CXX) -o $@ $(OBJS) $(LFLAGS) $(LDFLAGS)

$(OBJS):%.o:%.cpp $(HEADS)
	$(CXX) $(CXXFLAGS) $< -o $@
	
install:
	cp -f $(TARGET) /huishoubao/cgi/server/
	
clean:
	rm -f $(OBJS) $(TARGET)
