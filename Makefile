all:
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o prog *.o
clean:
	rm -rf prog *.h.gch
	rm -rf prog *.o
run:
	./prog