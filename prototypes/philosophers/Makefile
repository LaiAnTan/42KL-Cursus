
# ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

params = 1 800 200 200 7

all: compile run

db: debug run

lc: debug leaks

compile :
		gcc *.c -o philo

debug :
		gcc -fsanitize=thread -g3 *.c -o philo

leaks : compile
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo $(params)

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
