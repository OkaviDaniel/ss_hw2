CC=gcc
FLAGS= -Wall -g
AR = ar
OBJECT_MAIN = main.o
OBJECT_LIB = libmylib.a
OBJECT_BANK = myBank.o

all: $(OBJECT_LIB) progmains
progmains: $(OBJECT_MAIN) $(OBJECT_LIB)
	$(CC) $(FLAGS) -o progmains $(OBJECT_MAIN) $(OBJECT_LIB)
$(OBJECT_LIB): $(OBJECT_BANK) 
	$(AR) -rcs $(OBJECT_LIB) $(OBJECT_BANK)
$(OBJECT_MAIN): main.c myBank.h
	$(CC) $(FLAGS) -c main.c
$(OBJECT_BANK): myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
clean:
	rm -f progmains *.o *.a