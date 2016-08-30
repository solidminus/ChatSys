CC=g++
CVERSION=c++14
CFLAGS=-O2
CDEBUG=-Wall

FILES = src/ChatSys.cpp src/core.cpp src/tokens.cpp src/core.h src/tokens.h

TARGET = build/Chatsys.o

DEL = rm -f build/* 

all:
	@echo "Building target project"
	$(CC) $(CFLAGS) -std=$(CVERSION) $(CDEBUG) -o $(TARGET)  $(FILES)

clean:
	@echo "Cleanup started"
	$(DEL)

foo:
	@echo "f**k you!"
