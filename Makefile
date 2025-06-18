# (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>

# Variables
BIN_DIR = bin

# Build rules
.PHONY: clean all

all: $(BIN_DIR)/mem.o $(BIN_DIR)/newish.o $(BIN_DIR)/io.o $(BIN_DIR)/appinfo.o $(BIN_DIR)/cmds.o $(BIN_DIR)/ctrl.o $(BIN_DIR)/atr.o $(BIN_DIR)/parser.o $(BIN_DIR)/error.o $(BIN_DIR)/util.o
	$(CC) $(LDFLAGS) $(BIN_DIR)/mem.o $(BIN_DIR)/newish.o $(BIN_DIR)/io.o $(BIN_DIR)/cmds.o $(BIN_DIR)/ctrl.o $(BIN_DIR)/appinfo.o $(BIN_DIR)/atr.o $(BIN_DIR)/parser.o $(BIN_DIR)/error.o $(BIN_DIR)/util.o -o $(BIN_DIR)/newish

$(BIN_DIR)/newish.o: newish.c
	$(CC) $(CFLAGS) -c newish.c -o $(BIN_DIR)/newish.o

$(BIN_DIR)/io.o: io.c
	$(CC) $(CFLAGS) -c io.c -o $(BIN_DIR)/io.o

$(BIN_DIR)/appinfo.o: appinfo.c
	$(CC) $(CFLAGS) -c appinfo.c -o $(BIN_DIR)/appinfo.o

$(BIN_DIR)/cmds.o: cmds.c
	$(CC) $(CFLAGS) -c cmds.c -o $(BIN_DIR)/cmds.o

$(BIN_DIR)/ctrl.o: ctrl.c
	$(CC) $(CFLAGS) -c ctrl.c -o $(BIN_DIR)/ctrl.o

$(BIN_DIR)/atr.o: atr.c
	$(CC) $(CFLAGS) -c atr.c -o $(BIN_DIR)/atr.o

$(BIN_DIR)/parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c -o $(BIN_DIR)/parser.o

$(BIN_DIR)/error.o: error.c
	$(CC) $(CFLAGS) -c error.c -o $(BIN_DIR)/error.o

$(BIN_DIR)/mem.o: mem.c
	$(CC) $(CFLAGS) -c mem.c -o $(BIN_DIR)/mem.o

$(BIN_DIR)/util.o: util.c
	$(CC) $(CFLAGS) -c util.c -o $(BIN_DIR)/util.o

clean:
	$(RM) $(BIN_DIR)/*.o
	$(RM) $(BIN_DIR)/newish
