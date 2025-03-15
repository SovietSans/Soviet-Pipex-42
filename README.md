# Pipex 42

How to use the program :

> make
> ./pipex infile "cmd1" "cmd2" outfile
 
like in bash :

> "< infile "cmd1" | "cmd2" > outfile"

### If you want to use multipipe and here_doc :

in bash command use :

> make bonus
> ./pipex infile "cmd1" ... "cmdn" outfile

with here_doc :

> ./pipex here_doc LIMITER "cmd1" ... "cmdn" outfile

like in bash :

> << here_doc LIMITER cmd1 | cmd2 >> outfile
