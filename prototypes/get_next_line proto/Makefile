all : compile run

compile :
		gcc -o compiled *.c

debug :
		gcc -o compiled *.c -g

run :
		.\compiled.exe

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c