
params = 4 1 200 200 7

all: compile run

lc: debug leaks

compile :
		gcc *.c -o philo

debug :
		gcc -g -O1 *.c -o philo

leaks :
		valgrind --leak-check=full --show-leak-kinds=all ./philo $(params)

run :
		./philo $(params)

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c
