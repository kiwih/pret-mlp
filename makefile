CC=gcc

all: main.c nnetwork.c nnetwork_config.c nnetwork_config.h nnetwork.h
	$(CC) -o pret-mlp main.c nnetwork.c nnetwork_config.c

clean:
	rm pret-mlp