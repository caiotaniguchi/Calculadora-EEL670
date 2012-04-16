CC=g++
EXEC=calculator
OBJS=calculator.o userInterface.o stringError.o stringCalc.o
#CODE=calculator.cpp userInterface.cpp stringError.cpp stringCalc.cpp
FLAGS=-W -Wall

all: $(EXEC)

calculator: $(OBJS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -rf *.o

cleanall:
	rm -rf $(EXEC) *.o *~ 

