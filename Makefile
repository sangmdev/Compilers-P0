CC = gcc
CFLAGS = -g -Wall
TARGET = main
OBJ = main.c tree.c tree.h 

all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o P0 $(OBJ) $(LIBS)
clean:
	rm -f *.o $(TARGET)
	rm -f P0 
	rm -f *.inorder
	rm -f *.preorder
	rm -f *.postorder
