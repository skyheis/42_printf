/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkrulesconflict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:51:25 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/17 18:06:37 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_checkrulesconflict(t_varpc *svar)
{
	if (svar->flag_32)
	{
		if (svar->flag_plus)
			svar->flag_32 = 0;
	}
	if (svar->flag_zero)
	{
		if (svar->flag_dash || svar->flag_prec)
			svar->flag_zero = 0;
	}
}
