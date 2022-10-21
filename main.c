/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:25:21 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/21 01:16:50 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	printf("'%s'\n", ft_testino("%07u\n"));
	printf("'%07u'\n", 42);
	printf("'%s'\n", ft_testino("%u\n"));
	printf("'%u'\n", 42);
	printf("'%s'\n", ft_testino("%8u\n"));
	printf("'%8u'\n", 42);
	printf("'%s'\n", ft_testino("%.8ui\n"));
	printf("'%.8u'\n", 42);
	printf("'%s'\n", ft_testino("%8.4u\n"));
	printf("'%8.4u'\n", 42);
	printf("'%s'\n", ft_testino("%-8.4u\n"));
	printf("'%-8.4u'\n", 42);
	printf("'%s'\n", ft_testino("%-.5u\n"));
	printf("'%-.5u'\n", 42);
//	printf("'%s'\n", ft_testino("%+8.6i"));
//	printf("'% 8.6i'\n", -42);
//	printf("'%-+.6i'\n", 42);
//	printf("'%-+6i'\n", -42);
//	printf("'%-+6i'\n", 42);
//	printf("'%- .3i'\n", -42);
//	printf("'%- 6i'\n", 42);
//	printf("'%-6i'\n", -42);
//	printf("'%-6i'\n", 42);
	//printf("%i\n", ft_pcfinded("% +0-11110.11231x  "));
	//printf("'%-10.03s'  ", "abcdefghijk" );
	//printf("printf %10.197i  ", 10 );
}

// main printf
/*int	main(void)
{
	ft_printf("", );
	ft_printf("", );
	ft_printf("", );
	ft_printf("", );
	ft_printf("", );
}*/


// main checkstr
/*int	main(void)
{
	printf("%i \n", ft_checkstrpc("% -mc"));
	printf("%i \n", ft_checkstrpc("%+010 -12121.0001090s"));
	printf("%i \n", ft_checkstrpc("%+ -.100 s"));
	printf("%i \n", ft_checkstrpc("%12212.100s"));
	printf("%i \n", ft_checkstrpc("% -X"));
	printf("%i \n", ft_checkstrpc("%1112231312d"));
}*/


// main struct
/*void	ft_svarprint(t_varpc	*lol)
{
	printf("char %c\n", lol->ascii);
	printf("len  %i\n", lol->length);
	printf("32   %i\n", lol->flag_32);
	printf("plus %i\n", lol->flag_plus);
	printf("shar %i\n", lol->flag_sharp);
	printf("dash %i\n", lol->flag_dash);
	printf("zero %i\n", lol->flag_zero);
	printf("prec %i\n", lol->flag_prec);
}


int	main(void)
{
	t_varpc	*lol;

	lol = ft_svarnew('c');
	lol->flag_32 = 1;
	lol->flag_zero = 1;
	lol->flag_prec = 1;
	lol->flag_plus = 1;
	ft_checkrulesconflict(lol);
	ft_svarprint(lol);
}*/
