# 42KL-Minishell

## A simple shell program inspired by BASH.

This project is part of the 42 common core. It attempts to recreate BASH using the C language.
Features:
- Prompt display
- Working history
- Command execution
- Environment variables
- Command piping and redirection
- Quotation marks
- Signals
- A few bultin commands: cd, echo, exit, export, env, pwd, unset
- Exit codes

## Dependencies
- gcc with the readline library
- GNU make
## Installation

1. ```git clone https://github.com/LaiAnTan/42KL-Minishell``` to clone this repository
2. ```make``` to create the executable
3. ```./minishell``` to run the program
4. to remove program, run ```make fclean```

## Contributors

- cshi-xia (@SphagettiCodes)
- tlai-an (Myself)

## Known issues

1.	variables inside variables currently does not work, will not fix in the forseeable future
	> ```export A="hi" export B="$A"``` and then ```echo $B``` 
