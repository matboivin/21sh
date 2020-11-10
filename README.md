# ft_sh

<p align="center">
  <img src="doc/assets/bash-article-diagram.png" alt="bash diagram" />
</p>

Image source: [The Bourne-Again Shell](https://www.aosabook.org/en/bash.html)

## TODO

SIGNAUX

`SIGINT`
`SIGQUIT`

> When Bash is interactive, in the absence of any traps, it ignores SIGTERM (so that ‘kill 0’ does not kill an interactive shell), and SIGINT is caught and handled (so that the wait builtin is interruptible). When Bash receives a SIGINT, it breaks out of any executing loops. In all cases, Bash ignores SIGQUIT. If job control is in effect (see Job Control), Bash ignores SIGTTIN, SIGTTOU, and SIGTSTP. [(Source)](https://www.gnu.org/software/bash/manual/html_node/Signals.html)

[Why does Ctrl-D (EOF) exit the shell?](https://unix.stackexchange.com/questions/110240/why-does-ctrl-d-eof-exit-the-shell)

Fonctions:
- Récupérer le code du rush minitalk : register_signal_handlers()
- 2 signal handlers
- 1 loop
- status

--------

LEXER-PARSER-AST

Le plus gros du travail

--------

EXECUTION

- Récupérer le code du rush pipex

--------

CI

- Automatiser tests

