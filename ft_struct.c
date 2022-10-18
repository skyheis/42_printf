/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:51:14 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/18 21:52:37 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_varpc	*ft_svarnew(char ascii)
{
	t_varpc	*new;
	
	new = malloc(sizeof(t_varpc));
	if (!new)
		return (NULL);
	new->ascii = ascii;	
	new->length = 0;
	new->prec = -1;
	new->flag_32 = 0;
	new->flag_plus = 0;
	new->flag_sharp = 0;
	new->flag_dash = 0;
	new->flag_zero = 0;
	return (new);
}

void	ft_svardel(t_varpc *svar)
{
	free(svar);
}
