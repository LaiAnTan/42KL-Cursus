all : compile run

compile :
		gcc -Wall -Wextra -Werror *.c 

debug :
		gcc -o compiled *.c -g

run :
		./a.out

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c