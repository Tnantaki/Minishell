# Mimishell
## Progress of this project
#### Part1 : Lexer (90%)
#### Part2 : Parser (90%)
#### Part3 : Execution (80%)
#### Part4 : Built-in (40%)
#### Signal (90%)
#### Bonus (0%)
## The Program start at main.c
in main function will seperate into 4 Part.
### Part 1 : Lexer
1. Valid Systax : Command line must don't have some special char or unquoted.
- `(` Check are there unclosed parenthesis. <br>
- `'` `"` Check are there unclosed quotes. <br>
2. tokenization : will seperate the command line into tokens.
3. classify_token : will classify the type of tokens
- Command.
- Argument.
- Redirection
- Filename
- Pipe
4. Valid Token :
- Never have `|` or `||` near tokens. <br>
### Part 2 : Parser
1. Variable Expansion : `$` will searching the variable in envp and get the value from it. <br>
2. Parser : will arrange the token into simple command struct.
- Don't have to handle Command Substitution : `$()` that make Shell will fork child and execute the command Substitution first and store the value in struct simple command. <br>
### Part 3 : Execution
1. Pipe Creation : if there is pipe, Create pipe.
2. Redirections : The Shell will interpret input/output redirections and using function dup2 to redirect.
3. Executor : There are 2 alternative possible execution.
- Built-in command : if command are listed on Built-in. Shell will execute in parent process.
- Non Built-in command : The Shell will create child process by forking and execute the command.
4. Exit Status : Once command has completed, Shell record exit status.
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
### Bonus Part
1. Handle `&&` and `||` with parathesis for priorities.<br> 
2. Wildcards `*` <br>