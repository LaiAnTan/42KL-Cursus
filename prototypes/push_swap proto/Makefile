parameters = 67 72 -3 84 42 37 -91 68 -64 12 -78 45 -50 76 -99 52 96 78 -38 -93 40 20 92 -4 -10 47 91 50 82 70 -48 90 26 -12 -54 -95 35 -47 85 19 -34 87 69 63 -83 -5 -39 -9 10 5 22 62 -53 -87 73 61 18 6 53 80 30 -80 94 21 -21 58 -69 44 -25 2 -89 86 27 -67 -58 38 24 48 -6 11 -1 29 -31 75 -2 28 79 -55 3 -33 -94 49 51 -52 -8 -82 -71 -65 -92 97

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
