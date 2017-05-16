INC_DIR:=./
SRC_DIR:=./
SRCS:=$(wildcard *.cc)
OBJS:=$(patsubst %.cc, %.o, $(SRCS))
LIBS:=-lpthread

CXX:=g++
CXXFLAGS:=-w -g -std=c++11 $(addprefix -I, $(INC_DIR)) -Wno-deprecated

EXE:=./server.exe

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(CXXFLAGS) $(OBJS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
