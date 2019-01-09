CC = gcc
CFLAGS = -Wall
HEADERS = tasks.h func.h
OBJECTS = tasks.o func.o tema3.o
EXEC = exec

.PHONY = default build clean

default: build

build: exec

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

run_task1: exec
	./exec 1
run_task2: exec
	./exec 2
run_task3: exec
	./exec 3
run_task4: exec
	./exec 4
run_bonus: exec
	./exec bonus
clean:
	rm $(OBJECTS)
	rm $(EXEC)
	rm *.bmp
