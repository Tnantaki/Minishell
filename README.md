# Mimishell
## The Program start at main.c
in main function will seperate into 4 Part.
### Part 1 : Lexer
1. Valid Quote : Command line must don't have unclosed quoted.
 - `'` `"` Check are there unclosed quotes. <br>
2. tokenization : will seperate the command line into tokens.
3. classify_token : will classify the type of tokens
 - Command.
 - Argument.
 - Redirection
 - Filename
 - Pipe
4. Valid Syntax :
- Never have `|` or `||` near tokens. <br>
- Never have `<`,`<<`,`>`,`>>` by didn't follow filename. <br>
### Part 2 : Parser
1. Variable Expansion : `$` will searching the variable in envp and get the value from it. <br>
2. Trim quote : Outer quote will be trim. Both of `'`(Single quote) and `"`(Double quote). <br>
3. Parser : will arrange the token into simple command struct.
### Part 3 : Execution
1. If there are here_doc in command line, Create all here_doc first.
2. Pipe Creation : if there is pipe, Create pipe.
3. Executor :
 - There are 2 alternative possible execution.
 1. Built-in command : if command are listed on Built-in.
  - if **No pipe** Shell will open files, redirection and execute in parent process.
  - else Shell will fork child to open files, redirection and execute.
 2. Non Built-in command : The Shell will create child process by forking open files, redirection and execute the command.
4. Exit Status : Wait process to record exit status.
5. Cleanup :
 - Closing all file descriptors
 - Free all memory
### Part 4 : Built-in
1. echo
2. cd
3. pwd
4. export
5. unset
6. env
7. exit
#### Signal (additional)
1. Handle interrupt signal `Ctrl+C`.<br>
2. Handle quit signal `Ctrl+\`.<br>
