all:
	clear
	gcc index.c -o hamming.o 
	chmod +x hamming.o
	./hamming.o

