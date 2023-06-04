
--redirection--

- "<" should redirect input.
- ">" should redirect output.
- "<<" should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
- ">>" should redirect output in append mode.

redirections are handled left to right no matter what

redirection identifier without a (*) is an error
(*) input redirection : existing filename only
(*) output redirection : existing / potential filename

eg: ls > a > b > c
output: files a, b and c are created, but the output is written only inside c

eg: cat < a < b < c
output: only file c is redirected as input

eg: cat < a << EOF < c
output: STDIN is read until EOF is found, only then file c is redirected as input

eg: cat < a b
output: b is output since cat reads from parameter first 

for multiple commands:
redirections should be done inside the child process, 
but before the alteration of the command's input and output
this is because redirections override piping