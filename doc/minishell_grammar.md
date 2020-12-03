# Grammar for minishell

Adapted from: [Shell Command Language (POSIX)](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html)

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


%token  AND_IF    OR_IF    DGREAT
/*      '&&'      '||'     '>>'     */


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
cmd_suffix       : WORD
                 | WORD io_file
                 |      io_file
                 ;
io_file          : LESS      WORD
                 | GREAT     WORD
                 | DGREAT    WORD
                 ;
```

command: en fait une liste de commandes donc à fix ensuite  

simple_command:  

| Grammar rule            |                        | Examples                   |
| ----------------------- | ---------------------- | -------------------------- |
| io_file WORD cmd_suffix | < infile CMD > outfile | `< infile wc -c > outfile` |
| io_file WORD            | < infile CMD           | `< infile wc -c`           |
| WORD cmd_suffix         | CMD > outfile          | `ls > outfile` or `ls -la` |
| io_file                 | > outfile              | `> outfile`                |
| WORD                    | CMD                    | `ls`                       |
