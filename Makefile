CC=g++
EXEC=main
OBJS=main.o userInterface.o functionSelector.o stringError.o commands.o varToNumber.o expressionError.o varManager.o stringCalc.o
#CODE=main.cpp userInterface.cpp stringError.cpp stringCalc.cpp
CFLAGS=-W -Wall -Wpointer-arith

all: $(EXEC)

main: $(OBJS)
	$(CC) -o $@ $^ -lboost_regex 

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

cleanAll:
	rm -rf $(EXEC) *.o *~ 

