
params = here_doc "gay" "cat" "grep sus" "cat -e" outfile.txt

# infile.txt "cat -e" "pizza" "ls" "wc -l" "cat" "pizza" "ls" infile.txt

all: compile run

lc: debug leaks

compile :
		gcc *.c -o pipex

debug :
		gcc -g -O1 *.c

leaks :
		valgrind --leak-check=full --show-leak-kinds=all ./pipex $(params)

run :
		./pipex $(params)

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.c
