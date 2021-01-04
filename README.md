# ft_sh

`minishell` is an individual school project at [42 Paris](https://www.42.fr) campus.

42 is a private, non-profit and tuition-free Computer Science school based on peer-to-peer learning and hands-on projects.  
All programs written in C follow [42 style guideline](https://github.com/42Paris/norminette).

> A minimalist interactive shell mimicking bash.

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

### TODO for 21sh

- [ ] Hashtable for search command
- [ ] Stack error messages
- [ ] Termcaps: line editing, cursor, ...
- [ ] Handle AND_IF and OR_IF
- [ ] IO_HERE ('<<')
- [ ] Wildcards
- [ ] Autocomplete
- [ ] Refactor a lot of parts

### Acknowledgements

School project done at [42 Paris](https://www.42.fr).
