# Process

1. Read the command line
2. Interpret the command
3. Execute the command
4. Return the result
5. Collects the command return status

## Organisation

1. Parsing

- Reads the command line and stores it in an Abstract Syntax Tree (AST).
- Is composed of:
  - A lexer (Lexical Analyzer​): splits the command into tokens.
  - A parser: processes the tokens according to a grammar and builds the AST.

2. Execution

- Traverse the AST and execute commands.
- Create pipes to communicate the output of one process to the input of the next one.
- Handle redirections.

3. ​Subsystems

- Environment Variables: set, expand and print environment variables.
- Wildcards (bonus)
- Subshells (not required for the minishell school project)

## Steps

### Get the environment

```c
int main (int argc, char **argv, char **envp)
```

> The `envp` argument gives the program’s environment; it is the same as the value of environ.

[GNu.org: Program Arguments](https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html)

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

[Gnu.org: Environment Access](https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html)

### Shell prompt

Run an infinite loop that displays a prompt and wait for the user's input.

[Guide to Unix/Explanations/Shell Prompt](https://en.wikibooks.org/wiki/Guide_to_Unix/Explanations/Shell_Prompt)

Implement a `ft_readline()` function.

> Bash expands and displays PS1 before reading the first line of a command, and expands and displays PS2 before reading the second and subsequent lines of a multi-line command. Bash expands and displays PS0 after it reads a command but before executing it. See Controlling the Prompt, for a complete list of prompt string escape sequences.  [(Source)](https://www.gnu.org/software/bash/manual/html_node/Bash-Variables.html#Bash-Variables)

### Register signal handling (basic way first)

> When Bash is interactive, in the absence of any traps, it ignores SIGTERM (so that ‘kill 0’ does not kill an interactive shell), and SIGINT is caught and handled (so that the wait builtin is interruptible). When Bash receives a SIGINT, it breaks out of any executing loops. In all cases, Bash ignores SIGQUIT. If job control is in effect (see Job Control), Bash ignores SIGTTIN, SIGTTOU, and SIGTSTP. [(Source)](https://www.gnu.org/software/bash/manual/html_node/Signals.html)

Resource: [Why does Ctrl-D (EOF) exit the shell?](https://unix.stackexchange.com/questions/110240/why-does-ctrl-d-eof-exit-the-shell)

> Control-C is fatal error signal 2, (130 = 128 + 2)

Resource: [Appendix E. Exit Codes With Special Meanings](https://tldp.org/LDP/abs/html/exitcodes.html)

> The exit status of an executed command is the value returned by the waitpid system call or equivalent function. Exit statuses fall between 0 and 255, though, as explained below, the shell may use values above 125 specially. Exit statuses from shell builtins and compound commands are also limited to this range. Under certain circumstances, the shell will use special values to indicate specific failure modes.  For the shell’s purposes, a command which exits with a zero exit status has succeeded. A non-zero exit status indicates failure. This seemingly counter-intuitive scheme is used so there is one well-defined way to indicate success and a variety of ways to indicate various failure modes. When a command terminates on a fatal signal whose number is N, Bash uses the value 128+N as the exit status. 

[3.7.5 Exit Status](https://www.gnu.org/software/bash/manual/html_node/Exit-Status.html)

> In all cases, Bash ignores `SIGQUIT`.  [(Source)](https://www.gnu.org/software/bash/manual/html_node/Signals.html)

* `SIG_IGN`: Ignores the signal. Usage: `signal(SIGINT, SIG_IGN)`.
* `SIG_DFL`: Sets the default behaviour for the signal. This is useful when you want to reset the behaviour for a signal after having made some modifications. Usage: `signal(SIGINT, SIG_DFL)`.

### Parsing

Steps:

- The command string is passed to the lexer
- The string is split into tokens
- The parser transforms the tokens into and abstract syntaxt tree
- Traverse the abstract syntax tree to execute the commands

### Lexer

- Pass the command line to the lexer
- Tokenize the input
  - Process input char by char
  - Backtracking
- Pass the tokens to the parser

See 2.3 Token Recognition: [Shell Command Language (POSIX)](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html)

#### Quoting/escaping meta-characters

> First thing you have to understand is that certain characters, called meta-characters, have special meanings. The actual meaning depends on the program that sees this meta-character. Some characters are special to the Unix shell, and some are special to a utility like sed or grep.  
Before you study regular expressions, it is important that you understand how to use the shell to send regular expressions to a program. Or to put it another way, you want to say "Hey Shell. Ignore these meta-characters. I want the utility to treat them special, not you!" The mechanism to do this is called quoting. In other works, you put quotes around the meta-characters to inticate to the shell that they are not special - as far as the shell is concerned. When you quote a character, you ask the shell to leave it alone - and pass it on unchanged to the utility.  [(Source)](https://www.grymoire.com/Unix/Quote.html)

| Symbol   | Use                    |
| -------- | ---------------------- |
| `\`      | Single Character Quote |
| `"`      | Weak Quotes            |
| `'`      | Strong Quotes          |

See 2.2 Quoting: [Shell Command Language (POSIX)](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html)

### Parsing

The parser:

- checks for grammar errors
- processes the tokens into an Abstract Syntax Tree (AST)
- visitor to navigate the AST

#### Debug mode

Save the AST to [.dot](https://en.wikipedia.org/wiki/DOT_(graph_description_language)) and then to .svg.

```
digraph graphname {
    a -> b -> c;
    b -> d;
}
```

### Word Expansions



## Execution

- Eval all nodes
- Execute: open fd, launch processes

### Pipes

> If the parent wants to receive data from the child, it should close fd[1], and the child should close fd[0]. If the parent wants to send data to the child, it should close fd[0], and the child should close fd[1]. Since descriptors are shared between the parent and child, we should always be sure to close the end of pipe we aren't concerned with. On a technical note, the EOF will never be returned if the unnecessary ends of the pipe are not explicitly closed. [(Source)](https://tldp.org/LDP/lpg/node11.html)

```c
int dup(int oldfd);
```

```
oldfd ----------------+----------> resource
                      |
return_value ---------+
```

`oldfd` and the return value are both fd that point to the resource.

```c
int dup2(int oldfd, int newfd);
```

```
oldfd ---  (dup2 cuts access   )       --+------------> resource
                                         |
newfd -----------------------------------+
```

`oldfd` is closed while `newfd` is the duplicate of `oldfd`.

`dup2()` makes `newfd` be the copy of `oldfd`, closing `newfd` first if necessary, but note the following:

- If `oldfd` is not a valid file descriptor, then the call fails, and `newfd` is not closed. 
- If `oldfd` is a valid file descriptor, and `newfd` has the same value as `oldfd`, then `dup2()` does nothing, and returns`newfd`.

Source: [Programmation systeme: execve(), fork() et pipe()](https://n-pn.fr/t/2318-c--programmation-systeme-execve-fork-et-pipe)

### Redirections

Keep the last `io_file`.

For example, "test" is written to `file2`.

```console
echo "test" > file1 > file2
echo "test" >> file1 >> file2
```

And the following prints `file2`.

```console
cat < file1 < file2
```

> When you use `>`, the file is opened in truncation mode so its contents are removed before the command attempts to read it.  
When you use `>>`, the file is opened in append mode so the existing data is preserved.  [(Source)](https://superuser.com/questions/597244/why-does-redirecting-the-output-of-a-file-to-itself-produce-a-blank-file)

That's why the command below produces an empty `file1` and writes in `file2`.

```console
echo "test" > file1 > file2
```

Also, if `file1` has something written in it, and we run the following, `file1` will be empty.

```console
> file1
```

## Built-in commands

### env

> If no command name is specified following the environment specifications, the resulting environment is printed. This is like specifying the printenv program.  [(Source)](https://www.gnu.org/software/coreutils/manual/html_node/env-invocation.html)

### unset

[unset(1p) [posix man page]](https://www.unix.com/man-page/posix/1p/unset/)
