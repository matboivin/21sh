# Process

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
