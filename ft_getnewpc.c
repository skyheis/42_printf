/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnewpc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:39:14 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/18 22:24:37 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pcfinded(char *pc)
{
	char	ascii;
	t_varpc	*svar;
	
	ascii = ft_checkstrpc_endok(pc);
	printf("ascii is %c\n", ascii);
	if (ascii)
	{
		svar = ft_svarnew(ascii);
		printf("pc is '%s'\n", pc);
		if (!svar)
			return (0);
		if (ft_checkstrpc_gook(pc, svar))
			return (1);
		else
		{
			printf("OPS\n");
			ft_svardel(svar);
		}
	}
	return (0);
}
