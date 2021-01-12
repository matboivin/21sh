# ft_sh

`minishell`, `21sh` and `42sh` are school projects at [42 Paris](https://www.42.fr) campus.

42 is a private, non-profit and tuition-free Computer Science school based on peer-to-peer learning and hands-on projects.  
All programs written in C follow [42 style guideline](https://github.com/42Paris/norminette).

> A minimalist interactive shell mimicking bash.

<p align="center">
  <img src="assets/ast.gif" alt="AST gif" width="800" />
</p>

> Debug mode: Each time an input is received, displays the tokens, draws the AST and displays the command table.

### Disclaimer

This project is a school assignment. It was done for **learning purposes** and is thus **not intended for production**.  
Don't copy. Learn.

This code is not the one that was turned in for `minishell`. It aims to evolve to `21sh` and `42sh`.

### Prerequisites

This program was developed on Debian Linux. It runs on Debian and Ubuntu.

- GNU make and a C compiler

### Dependencies

- [libft](https://github.com/matboivin/libft)

### Installing

Clone the repository and its dependencies:
```console
$ git clone --recursive https://github.com/matboivin/ft_sh
```

Change it to your working directory and run:
```console
$ make install && make
$ ./ft_sh
```

### ft_sh grammar

Adapted from: [Shell Command Language (POSIX)](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_10)

```
/* -------------------------------------------------------
   The grammar symbols
   ------------------------------------------------------- */
%token  WORD
%token  NEWLINE

%token  PIPE     LESS      GREAT     SEMI
/*      '|'      '<'       '>'       ';'      */


/* The following are the operators (see XBD Operator)
   containing more than one character. */


%token  DSEMI
/*      ';;'    */


%token  DLESS  DGREAT
/*      '<<'   '>>'    */


/* -------------------------------------------------------
   The Grammar
   ------------------------------------------------------- */
%start program
%%
program          : command NEWLINE
                 | NEWLINE
                 | /* empty */
                 ;
command          :              pipe_sequence
                 | command SEMI pipe_sequence
                 ;
pipe_sequence    :                    simple_command
                 | pipe_sequence PIPE simple_command
                 ;
simple_command   : io_file WORD cmd_suffix
                 | io_file WORD
                 | io_file
                 |         WORD cmd_suffix
                 |         WORD
                 ;
cmd_suffix       :            io_file
                 | cmd_suffix io_file
                 |            WORD
                 | cmd_suffix WORD
                 ;
io_file          : LESS      WORD
                 | GREAT     WORD
                 | DGREAT    WORD
                 ;
```

### Future improvements (next step: 21sh)

- [ ] Hashtable for command search
- [ ] Stack error messages
- [ ] Termcaps: line editing, cursor, ...
- [ ] History
- [ ] Handle AND_IF and OR_IF
- [ ] IO_HERE ('<<')
- [ ] Wildcards
- [ ] Autocomplete
- [ ] Save pwd
- [ ] export: Append values
- [ ] Timeout
- [ ] Better lexer
- [ ] Refactor a lot of parts

### License

<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a>

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc/4.0/).

### Acknowledgements

School project done at [42 Paris](https://www.42.fr).
