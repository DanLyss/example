TARGET = lab-06_int-vector
GCC = g++
SRCDIR = src
INCDIR = include
FLAGS = -Wall -Wextra -Werror

all: $(TARGET)

obj:
	mkdir -p obj

obj/main.o: obj $(SRCDIR)/main.cpp $(INCDIR)/my_vector.hpp | obj 
	$(GCC) $(FLAGS) -c $(SRCDIR)/main.cpp -o obj/main.o

obj/my_vector.o: $(SRCDIR)/my_vector.cpp $(INCDIR)/my_vector.hpp | obj
	$(GCC) $(FLAGS) -c $(SRCDIR)/my_vector.cpp -o obj/my_vector.o

$(TARGET): obj/main.o obj/my_vector.o
	$(GCC) obj/my_vector.o obj/main.o -o $(TARGET)

clean:
	rm -rf obj $(TARGET) && rm -rf obj/ 

.PHONY: clean all
