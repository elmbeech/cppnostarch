GCC := g++
ifdef PHYSICELL_CPP 
	GCC := $(PHYSICELL_CPP)
endif

CFLAGS := -std=c++11 -m64

output = model

CC := $(GCC) $(CFLAGS)

all: main.o Cell.o save.o
	$(CC) -o $(output) main.o Cell.o save.o

main.o: main.cpp
	$(CC) -c main.cpp 

Cell.o: Cell.cpp
	$(CC) -c Cell.cpp

save.o: save.cpp
	$(CC) -c save.cpp	
	
clean:
	rm -f *.o $(output)
	
version:
	cp v$(V)/* . 
	make
