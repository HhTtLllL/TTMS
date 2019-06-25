PROGRAM = TTMS

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

CC = gcc

C_FLAGS = -DDEBUG -c  -Wextra -ggdb -I.   
all: $(C_OBJECTS) 
	@echo compile...
	$(CC) $(C_OBJECTS) -lm -o $(PROGRAM)

.c.o:
	@echo link$< ...
	$(CC) $(C_FLAGS) $< -o $@

.PHONY:clean
clean:
	$(RM) $(C_OBJECTS) TTMS
