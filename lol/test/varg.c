/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:51:27 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/16 16:29:45 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	var_arg(char *str, ...)
{
	va_list	test;
	int	a;
	int	b;
	int	c;
	char	*e;

	va_start(test, str);
	a = va_arg(test, int);
	b = va_arg(test, int);
	c = va_arg(test, int);
	e = va_arg(test, char *);
	printf("%i", a);
	printf("%i", b);
	printf("%i", c);
	printf("\n%s", e);
	va_end(test);
}

int	main(void)
{
	var_arg("aaa", 1, 2, 3, "CIAOOOO");
}




/*    The va_list Type

    The va_list type is an array containing a single element of one structure containing the necessary information to implement the va_arg macro. The C definition of va_list type is given in ﬁgure 3.34.

    Figure 3.34: va_list Type Declaration

    typedef struct {
       unsigned int gp_offset;
       unsigned int fp_offset;
       void *overflow_arg_area;
       void *reg_save_area;
    } va_list[1];

    The va_start Macro

    The va_start macro initializes the structure as follows:

    reg_save_area The element points to the start of the register save area.

    overﬂow_arg_area This pointer is used to fetch arguments passed on the stack. It is initialized with the address of the first argument passed on the stack, if any, and then always updated to point to the start of the next argument on the stack.

    gp_offset The element holds the offset in bytes from reg_save_area to the place where the next available general purpose argument register is saved. In case all argument registers have been exhausted, it is set to the value 48 (6 * 8).

    fp_offset The element holds the offset in bytes from reg_save_area to the place where the next available floating point argument register is saved. In case all argument registers have been exhausted, it is set to the value 304 (6 * 8 + 16 * 16).
*/
