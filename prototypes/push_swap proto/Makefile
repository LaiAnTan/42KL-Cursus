parameters = 2 +01 3 4 5 6 7 2

all : compile run

lc: debug leaks

compile :
		gcc -Wall -Wextra -Werror *.c

debug :
		gcc -g -O1 -Wall -Wextra -Werror *.c

leaks :
		valgrind --leak-check=full --show-leak-kinds=all ./a.out $(parameters)

debug :
		gcc -o compiled *.c -g

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