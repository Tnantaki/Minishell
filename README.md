# Mimishell
## Progress of this project
#### Part1 : Lexer (50%)
#### Part2 : Parser (50%)
#### Part3 : Execution (50%)
#### Part4 : Built-in (0%)
#### Part5 : Signal (0%)
#### Part6 : Bonus (0%)
## The Program start at main.c
in main function will seperate into 4 Part.
### Part 1 : Lexer
1. Valid Systax : Command line must don't have some special char or unquoted.
- `(` Check there are unclosed parenthesis. <br>
- `'` `"` Check there are unclosed quotes. <br>
2. tokenization : will seperate the command line into tokens.
### Part 2 : Parser
1. Valid Token :
- Never have `|` or `||` near tokens. <br>
2. Variable Expansion : `$` will searching the variable in envp and get the value from it. <br>
3. classify_token : will classify the type of tokens
- Command.
- Argument.
- Redirection
- Filename
- Pipe
4. Parser : will arrange the token into simple command struct.
- Don't have to handle Command Substitution : `$()` The Shell will fork child and execute the command Substitution first and store the value in struct simple command. <br>
### Part 3 : Execution
1. Redirections : The Shell will interpret input/output redirections and using function dup2 to redirect
2. Executor : The Shell create new process and execute the command
3. Exit Status : Once command has completed, Shell record exit status
4. Cleanup :
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
### Additional Part
1. Set Signal (0%)
2. Set Envp (20%)
### Bonus Part
1. Handle `&&` and `||` with parathesis for priorities.<br> 
2. Wildcards `*` <br>