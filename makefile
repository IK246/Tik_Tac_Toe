compile.out: ttt.o
	gcc -o compile.out ttt.o
ttt.o: ttt.c
	gcc -c ttt.c
clean:
	rm *.o *.out
