/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnewpc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:39:14 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/21 01:12:59 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_id_handle_zero(t_varpc *svar, char *id, char itoa_0)
{
	size_t	k;

	k = 0;
	if (svar->flag_zero)
	{
		while (!ft_isdigit(id[k]))
			id[k++] = '0';
		if (itoa_0 == '-')
			id[0] = '-';
		else if (svar->flag_plus)
			id[0] = '+';
		else if (svar->flag_32)
			id[0] = ' ';
	}
	return (id);
}

void  ft_svarprint(t_varpc *lol)
{
        printf("char %c\n", lol->ascii);
        printf("len  %lu\n", lol->length);
        printf("prec %li\n", lol->prec);
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
//			ft_svarprint(svar);
			return (svar);
		}
		else
			ft_svardel(svar);
	}
	return (0);
}
