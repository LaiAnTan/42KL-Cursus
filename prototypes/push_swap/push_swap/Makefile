
parameters = 1 5 2 4 3

all: compile run

lc: debug leaks

compile :
		gcc *.c -o push_swap

debug :
		gcc -g -O1 *.c

leaks :
		valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(parameters)

run :
		./push_swap $(parameters)

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c
