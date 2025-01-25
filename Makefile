main: src/main.c
	gcc -I/home/rhys/dev/c/clox/include -o main src/main.c src/chunk.c src/memory.c src/debug.c

clean:
	rm main