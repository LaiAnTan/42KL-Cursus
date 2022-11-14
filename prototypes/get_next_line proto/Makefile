all : compile run

lc : compile leaks

compile :
		gcc -g -O1 -Wall -Wextra -Werror *.c

leaks :
		valgrind --leak-check=full --show-leak-kinds=all ./a.out

debug :
		gcc -o compiled *.c -g

run :
		./compiled.exe

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c