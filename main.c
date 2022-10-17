/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:25:21 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/17 18:09:45 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

// main printf
/*int	main(void)
{
	ft_printf("", );
	ft_printf("", );
	ft_printf("", );
	ft_printf("", );
	ft_printf("", );
}*/

// main struct
void	ft_svarprint(t_varpc	*lol)
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
}
