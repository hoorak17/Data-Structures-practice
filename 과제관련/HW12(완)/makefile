CC = g++
CFLAGS = -O2 -std=c++17
OBJS = hw12.o
TARGET = hw12

run: all
	./$(TARGET)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

hw12.o: hw12.cpp sort.h
	$(CC) $(CFLAGS) -c hw12.cpp

clean:
	rm -f *.o
	rm -f $(TARGET)