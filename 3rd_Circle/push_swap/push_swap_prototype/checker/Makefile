
parameters = 1 5 2 4 3

all: compile run

lc: debug leaks

compile :
		gcc *.c -o a.out

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
