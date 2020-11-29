# Grammar for minishell

Adapted from: [Shell Command Language (POSIX)](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html)

```
/* -------------------------------------------------------
   The grammar symbols
   ------------------------------------------------------- */
%token  WORD
%token  NEWLINE


/* The following are the operators (see XBD Operator)
   containing more than one character. */



%token  AND_IF    OR_IF
/*      '&&'      '||'     */


%token  DGREAT
/*      '>>'    */

/* -------------------------------------------------------
   The Grammar
   ------------------------------------------------------- */
%start program
%%
program          : command NEWLINE
                 | NEWLINE
                 | /* empty */
                 ;
command          :             pipe_sequence
                 | command ';' pipe_sequence
                 ;
pipe_sequence    :                   simple_command
                 | pipe_sequence '|' simple_command
                 ;
simple_command   : redirect_list WORD redirect_list
                 | redirect_list WORD
                 | WORD redirect_list
                 | redirect_list                 
                 | WORD
                 ;
redirect_list    :               io_file
                 | redirect_list io_file
                 ;
io_file          : '<'       WORD
                 | '>'       WORD
                 | DGREAT    WORD
                 ;
```
