CC=G++
CVERSION=c++14
CFLAGS=-O2
CDEBUG=-Wall

FILES = src/Chatsys.cpp

TARGET = build/Chatsys.o

all:
	$(CC) $(CFLAGS)-std=$(CVERSION) $(CDEBUG) -o $(TARGET)  $(FILES)

clean:
	$(DEL)

foo:
	@echo "f**k you!"
