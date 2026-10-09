CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -pedantic
CPPFLAGS = -Iinclude

TARGET = Dbl
OBJ = src/main.o src/Dbl.o

ifeq ($(OS), Windows_NT)
    DELETE = del /Q
    EXE = Dbl.exe
else
    DELETE = rm -f
    EXE = Dbl
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXE)

src/%.o: src/%.c include/Dbl.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
ifeq ($(OS), Windows_NT)
	-$(DELETE) $(OBJ) $(EXE)
else
	$(DELETE) $(OBJ) $(EXE)
endif

run: $(TARGET)
	./$(EXE)

.PHONY: all clean run