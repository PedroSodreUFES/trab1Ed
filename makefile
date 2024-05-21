CC=gcc
CFLAGS=-Wall -Wextra -std=c99
BIN_DIR=casos_de_teste

all: compile copy_to_folders

compile:
	$(CC) *.c -o main $(CFLAGS)

copy_to_folders: compile
	if [ ! -d $(BIN_DIR)/Facil ]; then mkdir -p $(BIN_DIR)/Facil; fi
	if [ ! -d $(BIN_DIR)/Dificil ]; then mkdir -p $(BIN_DIR)/Dificil; fi
	cp main $(BIN_DIR)/Facil/
	cp main $(BIN_DIR)/Dificil/

run_facil:
	cd $(BIN_DIR)/Facil && ./main

run_dificil:
	cd $(BIN_DIR)/Dificil && ./main

clean:
	rm -f main
