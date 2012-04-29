CC=g++
EXEC=main
OBJS=main.o userInterface.o functionSelector.o stringError.o commands.o expressionError.o varManager.o stringCalc.o
#-Wpointer-arith
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

