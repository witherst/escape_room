CXX = g++
CXXFLAGS += -g -std=c++11
#LDFLAGS =

OBJS = main.o menu.o inputValid.o sim.o item.o player.o space.o container.o building.o bloodRoom.o insertRoom.o leverRoom.o depressRoom.o lightRoom.o mathRoom.o

SRCS = main.cpp menu.cpp inputValid.cpp sim.cpp item.cpp player.cpp space.cpp container.cpp building.cpp bloodRoom.cpp insertRoom.cpp leverRoom.cpp depressRoom.cpp lightRoom.cpp mathRoom.cpp

HEADERS =

escapeRoom: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o escapeRoom

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

make clean:
	rm escapeRoom *.o
