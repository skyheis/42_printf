/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnewpc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:39:14 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/19 18:44:18 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void  ft_svarprint(t_varpc *lol)
{
        printf("char %c\n", lol->ascii);
        printf("len  %lu\n", lol->length);
        printf("prec %lli\n", lol->prec);
        printf("32   %i\n", lol->flag_32);
        printf("plus %i\n", lol->flag_plus);
        printf("shar %i\n", lol->flag_sharp);
        printf("dash %i\n", lol->flag_dash);
        printf("zero %i\n", lol->flag_zero);
}

t_varpc	*ft_pcfinded(char *pc)
{
	char	ascii;
	t_varpc	*svar;
	
	ascii = ft_checkstrpc_endok(pc);
	if (ascii)
	{
		svar = ft_svarnew(ascii);
		if (!svar)
			return (0);
		if (ft_checkstrpc_gook(pc, svar))
		{
			ft_svarprint(svar);
			return (svar);
		}
		else
			ft_svardel(svar);
	}
	return (0);
}
