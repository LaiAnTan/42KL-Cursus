parameters = 7 4 9 3 1 10 2 5 8 6

all : compile run

lc: debug leaks

compile :
		gcc -Wall -Wextra -Werror *.c

debug :
		gcc -g -O1 -Wall -Wextra -Werror *.c

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