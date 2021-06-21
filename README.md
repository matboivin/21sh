# ft_sh

`minishell`, `21sh` and `42sh` are school projects at [42 Paris](https://www.42.fr) campus.

42 is a private, non-profit and tuition-free Computer Science school based on peer-to-peer learning and hands-on projects.  
All programs written in C follow [42 style guideline](https://github.com/42Paris/norminette).

> A minimalist interactive shell mimicking bash.

<p align="center">
  <img src="assets/demo.gif" alt="demo" />
</p>

### Table of content

- [Requirements](#requirements)
  - [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
  - [Debug mode](#debug-mode)
  - [wandre mode](#wandre-mode)
- [Acknowledgements](#acknowledgements)

### Disclaimer

This project is a school assignment. It was done for **learning purposes** and is thus **not intended for production**.  
Don't copy. Learn.

This code is not the one that was turned in for `minishell`. It aims to evolve to `21sh` and `42sh`.

## Requirements

This program was developed on Debian Linux. It runs on Debian and Ubuntu.

- gcc
- make

### Dependencies

- [libft](https://github.com/matboivin/libft)

## Installation

1. Clone the repository and its dependencies:
```console
$ git clone --recursive https://github.com/matboivin/ft_sh
```

2. Change it to your working directory and run:
```console
$ make install && make
```

## Usage

```console
$ ./ft_sh
```

### Debug mode

Each time an input is received, this mode displays the tokens, draws the AST and displays the command table.

Ensure you ran `make install`.

```console
$ make debug
$ ./ft_sh
```

<p align="center">
  <img src="assets/ast.gif" alt="AST gif" width="800" />
</p>

### wandre mode

wandre will insult the user when they type a wrong command.

To wake up wandre, type `!wandre` in the `ft_sh`, and `!stopit_wandre` to deactivate it.

```console
./ft_sh 
┌─[ft_sh]─[~/path/to/ft_sh]
└──╼ !wandre
Warning /!\ The wandre mode is activated! Type '!stopit_wandre' to deactivate

    wandre: hi! :)

┌─[ft_sh]─[~/path/to/ft_sh]
└──╼ !stopit_wandre
wandre mode deactivated

    wandre: bye :)
```

<p align="center">
  <img src="assets/wandre_demo.gif" alt="wandre mode" />
</p>

Inspired by the [bash-insulter](https://github.com/hkbakke/bash-insulter).

For more wandre, click [here](https://github.com/matboivin/wandroulette).

## Acknowledgements

School project done at [42 Paris](https://www.42.fr).

## License

See `LICENSE` for more information.
