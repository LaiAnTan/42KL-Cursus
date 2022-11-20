parameters = 16 44 41 2 50 48 19 34 29 18 4 21 42 5 47 14 23 25 36 8 24 20 37 28 33 49 46 31 9 39 35 3 30 26 22 38 13 43 12 10 45 15 17 40 27 32 6 11 7 1

all : compile run

lc: debug leaks

compile :
		gcc *.c

debug :
		gcc -g -O1 *.c

leaks :
		valgrind --leak-check=full --show-leak-kinds=all ./a.out $(parameters)

run :
		./a.out $(parameters)

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c
