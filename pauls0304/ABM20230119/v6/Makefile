GCC := g++
ifdef PHYSICELL_CPP 
	GCC := $(PHYSICELL_CPP)
endif

CFLAGS := -std=c++11 -m64

CC := $(GCC) $(CFLAGS)

output := model 

all: main.o Cell.o save.o environment.o
	$(CC) -o $(output) main.o Cell.o save.o environment.o

main.o: main.cpp
	$(CC) -c main.cpp 

Cell.o: Cell.cpp
	$(CC) -c Cell.cpp
	
save.o: save.cpp
	$(CC) -c save.cpp 
	
environment.o: environment.cpp
	$(CC) -c environment.cpp 
	
clean:
	rm -f *.o $(output)
	
version:
	cp v$(V)/* . 
	make
