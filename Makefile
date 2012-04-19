CC=g++
EXEC=main
OBJS=main.o functionSelector.o commands.o userInterface.o stringError.o stringCalc.o
#CODE=main.cpp userInterface.cpp stringError.cpp stringCalc.cpp
CFLAGS=-W -Wall

all: $(EXEC)

main: $(OBJS)
	$(CC) -o $@ $^ -lboost_regex

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

cleanAll:
	rm -rf $(EXEC) *.o *~ 

