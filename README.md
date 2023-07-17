# rewriting printf in C without standard libraries

## Description

This project (if done with bonus) is the first big challenge of the 42 school. The goal is to rewrite the printf function in C without using standard libraries. The project is a great way to learn how to use variadic arguments, it was also a great way to learn how to use pointers and memory allocation.
The function will be prototyped as follow:

```c
int ft_printf(const char *, ...);
```

The function will manage the following conversions: cspdiuxX% and will manage any combination of the following flags: ’-0.*# ’ and minimum field width with all conversions. Also the project has to follow the [Norm](https://github.com/42School/norminette) of the school.

## Architecture

This was my really first time thinking about a project architecture. I wanted to make it as reusable as possible because all the conversion have similar use cases and I thought it would be a great way to thing a schema that could be used for all the conversions.

## How to use

If you want to use the function, you can clone the repository and compile the library with the following command:

```bash
make
```

Then you can compile your program with the library:

```bash
gcc -Wall -Wextra -Werror -I./includes -L. -lftprintf main.c
```

## Tests

I made test by hand, but I also used the following amazing work from a student of my network to test my function: [printf_tester](https://github.com/paulo-santana/ft_printf_tester)
