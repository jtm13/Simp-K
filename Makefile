CC = gcc
CFLAGS = -g -Wall
VPATH = src:bin
OBJ = bin/obj/

#-Wall -Wextra
#-Werror -std=gnu99

all: keylog

keylog: $(OBJ)keylog.o
	$(CC) $(CFLAGS) -o bin/keylog $^ 


%: %.c bin.txt
	$(CC) $(CFLAGS) -o bin/$@ $<

$(OBJ)%.o: %.c $(OBJ)obj.txt
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)obj.txt:
	mkdir -p $(OBJ)
	echo "Check." >> $(OBJ)obj.txt
	echo "Check." >> bin/bin.txt

bin.txt:
	mkdir bin
	echo "Check." >> bin/bin.txt

clean:
	rm -rf bin/obj/*
	rm -rf *.dSYM
	rm -rf *.class
	rm bin/keylog*
	rm keylog*
	rm *.o
