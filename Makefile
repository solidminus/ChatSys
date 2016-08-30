CC=g++
CVERSION=c++14
CFLAGS=-O2
CDEBUG=-Wall

FILES = src/ChatSys.cpp

TARGET = build/Chatsys.o

all:
	$(CC) $(CFLAGS) -std=$(CVERSION) $(CDEBUG) -o $(TARGET)  $(FILES)

clean:
	$(DEL)

foo:
	@echo "f**k you!"
