CC=g++
CVERSION=c++14
CFLAGS=-O2
CDEBUG=-Wall

MAIN = src/ChatSys.cpp
FILE1 = src/core.cpp src/tokens.cpp src/core.h src/tokens.h src/global.cpp
FILE2 = src/knowledge.h src/knowledge.cpp
FILES = $(FILE1) $(FILE2)

TARGET = build/Chatsys.o

DEL = rm -f build/*.o 

all:
	@echo "Building target project"
	$(CC) $(CFLAGS) -std=$(CVERSION) $(CDEBUG) -o $(TARGET)  $(MAIN) $(FILES)

clean:
	@echo "Cleanup started"
	$(DEL)

test:
	@echo "Test is not implemented"