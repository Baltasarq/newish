

.PHONY: clean all


all: mem.o newish.o io.o appinfo.o cmds.o ctrl.o atr.o parser.o error.o
	$(CC) $(LDFLAGS) mem.o newish.o io.o cmds.o ctrl.o appinfo.o atr.o parser.o error.o -o newish

newish.o: newish.c
	$(CC) $(CFLAGS) -c newish.c -o newish.o

io.o: io.c
	$(CC) $(CFLAGS) -c io.c -o io.o

appinfo.o: appinfo.c
	$(CC) $(CFLAGS) -c appinfo.c -o appinfo.o

cmds.o: cmds.c
	$(CC) $(CFLAGS) -c cmds.c -o cmds.o

ctrl.o: ctrl.c
	$(CC) $(CFLAGS) -c ctrl.c -o ctrl.o

atr.o: atr.c
	$(CC) $(CFLAGS) -c atr.c -o atr.o

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c -o parser.o

error.o: error.c
	$(CC) $(CFLAGS) -c error.c -o error.o

mem.o: mem.c
	$(CC) $(CFLAGS) -c mem.c -o mem.o

clean:
	$(RM) *.o
	$(RM) newish
