CC = gcc
CXX = g++


#FRAME_DIR=../cgi_frame
#DATABASE_DIR = ../CSLPlatMng_device/src/cgi_frame/database
#INC_DIR = api/include
#LIB_DIR = api/lib64
MAIN_DIR = .
INCLUDE = ../../include
RAPIDJSON = ../../include/rapidjson
MUDUO = $(INCLUDE)/muduo
MUDUO_LIB = ../../lib/muduo



CFLAGS = -c -Wall
CFLAGS += -g
CFLAGS += -std=c++11

CFLAGS += -fpic -lpthread




CFLAGS += -I$(INCLUDE)
CFLAGS += -I$(MAIN_DIR)
CFLAGS += -I$(RAPIDJSON)
CFLAGS += -I$(MUDUO)
CXXFLAGS = $(CFLAGS)






HEADS += $(wildcard $(MAIN_DIR)/*.h)


SOURCES += $(wildcard $(MAIN_DIR)/*.cpp)

OBJS = $(SOURCES:.cpp=.o)
TARGET = http_muduo_server


LDFLAGS = -Wl,-R /usr/local/lib
LDFLAGS += -pthread -lrt
LDFLAGS += -L$(MUDUO_LIB) -lmuduo_net -lmuduo_base -lmuduo_inspect -lmuduo_http 

all:$(TARGET)
$(TARGET):$(OBJS) $(SOURCES) $(HEADS)
	$(CXX) -o $@ $(OBJS) $(LFLAGS) $(LDFLAGS)

$(OBJS):%.o:%.cpp $(HEADS)
	$(CXX) $(CXXFLAGS) $< -o $@
	
install:
	cp -f $(TARGET) /huishoubao/cgi/server/
	
clean:
	rm -f $(OBJS) $(TARGET)
