

.PHONY: clean all


all: bin/mem.o bin/newish.o bin/io.o bin/appinfo.o bin/cmds.o bin/ctrl.o bin/atr.o bin/parser.o bin/error.o bin/util.o
	$(CC) $(LDFLAGS) bin/mem.o bin/newish.o bin/io.o bin/cmds.o bin/ctrl.o bin/appinfo.o bin/atr.o bin/parser.o bin/error.o bin/util.o -o bin/newish

bin/newish.o: newish.c
	$(CC) $(CFLAGS) -c newish.c -o bin/newish.o

bin/io.o: io.c
	$(CC) $(CFLAGS) -c io.c -o bin/io.o

bin/appinfo.o: appinfo.c
	$(CC) $(CFLAGS) -c appinfo.c -o bin/appinfo.o

bin/cmds.o: cmds.c
	$(CC) $(CFLAGS) -c cmds.c -o bin/cmds.o

bin/ctrl.o: ctrl.c
	$(CC) $(CFLAGS) -c ctrl.c -o bin/ctrl.o

bin/atr.o: atr.c
	$(CC) $(CFLAGS) -c atr.c -o bin/atr.o

bin/parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c -o bin/parser.o

bin/error.o: error.c
	$(CC) $(CFLAGS) -c error.c -o bin/error.o

bin/mem.o: mem.c
	$(CC) $(CFLAGS) -c mem.c -o bin/mem.o

bin/util.o: util.c
	$(CC) $(CFLAGS) -c util.c -o bin/util.o

clean:
	$(RM) bin/*.o
	$(RM) bin/newish
