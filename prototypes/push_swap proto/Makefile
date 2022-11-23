
parameters = 5 4 3 2 1

all: compile run

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
