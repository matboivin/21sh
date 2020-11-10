# Process

1. Read the command line
2. Interpret the command
3. Execute the command
4. Return the result

## Organisation

1. The Parser​

- Reads the command line and stores it in a Command Table structure.
- Is composed of:
  - A lexer (Lexical Analyzer​): splits the command into tokens.
  - A parser: processes the tokens according to a grammar and builds the Command Table.

<p align="center">
  <img src="assets/commandtable_plot.png" alt="Command Table" />
</p>

Images source: [Writing Your Own Shell (PDF)](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

2. The Executor​

- Takes the Command Table structure and creates a process for each Simple Command.
- Create pipes to communicate the output of one process to the input of the next one.
- Redirects the standard input, standard output, and standard error in case of redirections. 

3. ​Shell Subsystems

- Environment Variables: set, expand and print environment variables.
- Wildcards (bonus)
- Subshells (check if bonus)

## Steps

### Get the environment

```c
int main (int argc, char **argv, char **envp)
```

The `envp` argument gives the program’s environment; it is the same as the value of environ.

Resource: [GNu.org: Program Arguments](https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html)

### Functions to handle the environment

An array of strings to represent the environment.

> The environment is represented as an array of strings. Each string is of the format ‘name=value’. The order in which strings appear in the environment is not significant, but the same name must not appear more than once. The last element of the array is a null pointer.  [(Source)](https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html)

Functions to:

- Add a variable: `setenv` and `putenv`
- Delete a variable: `unsetenv`
- Find a variable: `find_env`
- Init the env by getting all the pairs: `init_env`
- Clear the env by deleting all the pairs: `clearenv`
- Get the value of a variable: `getenv`
- Print the env: `printenv`

Resource: [Gnu.org: Environment Access](https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html)

### Shell prompt

Run an infinite loop that displays a prompt and wait for the user's input.

Resource: [Guide to Unix/Explanations/Shell Prompt](https://en.wikibooks.org/wiki/Guide_to_Unix/Explanations/Shell_Prompt)

### Register signal handling (basic way first)

> When Bash is interactive, in the absence of any traps, it ignores SIGTERM (so that ‘kill 0’ does not kill an interactive shell), and SIGINT is caught and handled (so that the wait builtin is interruptible). When Bash receives a SIGINT, it breaks out of any executing loops. In all cases, Bash ignores SIGQUIT. If job control is in effect (see Job Control), Bash ignores SIGTTIN, SIGTTOU, and SIGTSTP. [(Source)](https://www.gnu.org/software/bash/manual/html_node/Signals.html)

[Why does Ctrl-D (EOF) exit the shell?](https://unix.stackexchange.com/questions/110240/why-does-ctrl-d-eof-exit-the-shell)

```
```

### Parsing

- Send the command line to the lexer.
- The parser builds the AST.
