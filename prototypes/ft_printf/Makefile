all : compile run

compile :
		gcc -Wall -Werror -Wextra *.c

run :
		./a.exe

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c