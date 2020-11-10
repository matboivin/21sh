# Notions

### Links

- [Data Processing - (Pipeline | Compose | Chain)](https://datacadamia.com/data/processing/pipeline)
- [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [Wiki ubuntu-fr: Initiation au Shell](https://doc.ubuntu-fr.org/projets/ecole/scripting/initiation_au_shell)
- [Shell Command Language (POSIX)](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html)

Bash  

- [The Bourne-Again Shell](https://www.aosabook.org/en/bash.html)
- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Bash - La variable d'environnement PATH](https://www.commentcamarche.net/faq/3585-bash-la-variable-d-environnement-path)

Env  

- [Gnu.org: Program Arguments](https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html)
- [Gnu.org: Environment Access](https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html)

Execution  

- [Shell search PATH – finding and running commands](http://teaching.idallen.com/cst8207/12f/notes/400_search_path.html)
- [Forward Slash Definition](http://www.linfo.org/forward_slash.html)
- [How do I use execve in C?](https://jameshfisher.com/2017/02/05/how-do-i-use-execve-in-c/)

Lexer, Parser and AST  

- [Let’s Build A Simple Interpreter](https://ruslanspivak.com/lsbasi-part1/)
- [Compiler Design - Top-Down Parser](https://www.tutorialspoint.com/compiler_design/compiler_design_top_down_parser.htm)
- [Shunting-yard algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm)
- [Grammars and Parsing](http://www.cs.cornell.edu/courses/cs2112/2015fa/lectures/lec_parsing/)
- [Lexing, Parsing & Evaluation](http://www-igm.univ-mlv.fr/~forax/ens/java-avance/cours/pdf/old/Generation%20de%20code%201.pdf)
- [Lecture 4: Implementing Lexers and Parsers](http://www.cse.chalmers.se/edu/year/2015/course/DAT150/lectures/proglang-04.html)
- [Analyse syntaxique : l'AST](http://www.gaudry.be/langages-analyse-syntaxique-ast.html)

Signals  

- [Signaux](https://sites.uclouvain.be/SystInfo/notes/Theorie/html/Fichiers/fichiers-signaux.html)
- [Wiki: C signal handling](https://en.wikipedia.org/wiki/C_signal_handling)
- [Signal Handling (Linux* OS and Mac OS* X only)](https://scc.ustc.edu.cn/zlsc/sugon/intel/compiler_f/main_for/bldaps_for/lin/bldaps_sighandl.htm)
- [Gnu.org: Signals](https://www.gnu.org/software/bash/manual/html_node/Signals.html)
- [Gnu.org: Termination Signals](https://www.gnu.org/software/libc/manual/html_node/Termination-Signals.html)
- [Signal Concepts](https://pubs.opengroup.org/onlinepubs/009695399/functions/xsh_chap02_04.html)
- [All about Linux signals](https://www.linuxprogrammingblog.com/all-about-linux-signals?page=show)
- [Passing Values to C Signal Handlers](http://sgeos.github.io/unix/c/signals/2016/02/24/passing-values-to-c-signal-handlers.html)
- [What does bash do when it receives the SIGINT signal?](https://unix.stackexchange.com/questions/400989/what-does-bash-do-when-it-receives-the-sigint-signal)
- [Writing a Unix Shell - Part III](https://indradhanush.github.io/blog/writing-a-unix-shell-part-3/)

* `SIG_IGN`: Ignores the signal. Usage: `signal(SIGINT, SIG_IGN)`.
* `SIG_DFL`: Sets the default behaviour for the signal. This is useful when you want to reset the behaviour for a signal after having made some modifications. Usage: `signal(SIGINT, SIG_DFL)`.

Pipes

- [Wiki: Pipeline (Unix)](https://en.wikipedia.org/wiki/Pipeline_(Unix))
- [Wiki: Anonymous pipe](https://en.wikipedia.org/wiki/Anonymous_pipe)
- [How do pipes and FIFOs work on Linux?](https://imjching.com/writings/2018/10/09/how-do-pipes-and-fifos-work-on-linux/)
- [6.2.2 Creating Pipes in C](https://tldp.org/LDP/lpg/node11.html)
- [Closing pipe file descriptor in C](https://stackoverflow.com/questions/22032120/closing-pipe-file-descriptor-in-c)
- [http://www.zeitoun.net/articles/communication-par-tuyau/start](http://www.zeitoun.net/articles/communication-par-tuyau/start)

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


# Built-in

## env

> If no command name is specified following the environment specifications, the resulting environment is printed. This is like specifying the printenv program.

- [23.2 env: Run a command in a modified environment](https://www.gnu.org/software/coreutils/manual/html_node/env-invocation.html)
