# Grammar for ft_sh

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
program          : command linebreak
                 | linebreak
                 ;
command          :              pipe_sequence
                 | command SEMI pipe_sequence
                 ;
pipe_sequence    :                              simple_command
                 | pipe_sequence PIPE linebreak simple_command
                 ;
simple_command   : io_file cmd_word cmd_suffix
                 | io_file cmd_word
                 | io_file
                 |         cmd_name cmd_suffix
                 |         cmd_name
                 ;
cmd_name         : WORD
                 ;
cmd_word         : WORD
                 ;
cmd_suffix       :            io_file
                 | cmd_suffix io_file
                 |            WORD
                 | cmd_suffix WORD
                 ;
io_file          : LESS      filename
                 | GREAT     filename
                 | DGREAT    filename
                 ;
filename         : WORD
                 ;
newline_list     :              NEWLINE
                 | newline_list NEWLINE
                 ;
linebreak        : newline_list
                 | /* empty */
                 ;
```

`simple_command` examples:

| Grammar rule                |                        | Examples                   |
| --------------------------- | ---------------------- | -------------------------- |
| io_file cmd_word cmd_suffix | < infile CMD > outfile | `< infile wc -c > outfile` |
| io_file cmd_word            | < infile CMD           | `< infile cat`             |
| cmd_name cmd_suffix         | CMD > outfile          | `ls > outfile` or `ls -la` |
| io_file                     | > outfile              | `> outfile`                |
| cmd_name                    | CMD                    | `ls`                       |
