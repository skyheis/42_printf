/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:03:29 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/19 16:36:32 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_atoi_custom(const char *pc)
{
	int	k;
	int	toi;

	k = 0;
	toi = 0;
	while (pc[k] >= '0' && pc[k] <= '9')
	{
		toi *= 10;
		toi += pc[k] - 48;
		k++;
	}
	return (toi);
}

int	ft_checkdoubleflag(char pcv, t_varpc *svar)
{
	if (pcv == 32)
	{
		if (svar->flag_32 || svar->length != 0)
			return (0);
		svar->flag_32 = 1;
	}
	else if (pcv == '+')
	{
		if (svar->flag_plus || svar->length != 0)
			return (0);
		svar->flag_plus = 1;
	}
	else if (pcv == '-')
	{
		if (svar->flag_dash || svar->length != 0)
			return (0);
		svar->flag_dash = 1;
	}
	else if (pcv == '#')
	{
		if (svar->flag_sharp || svar->length != 0)
			return (0);
		svar->flag_sharp = 1;
	}
	return (1);
}

int	ft_checkprecision(char **pc, t_varpc *svar)
{
	if (**pc == '.')
	{
		*pc = *pc + 1;
		if (!ft_isdigit(**pc))
			return (0);
		svar->prec = ft_atoi_custom(*pc);
		while (ft_isdigit(**pc))
			*pc = *pc + 1;
		if (**pc != 'c' && **pc != 's' && **pc != 'd' && **pc != 'i'
			&& **pc != 'u' && **pc != 'x' && **pc != 'X')
			return (0);
		*pc = *pc - 1;
	}
	return (1);
}

int	ft_checkstrpc_gook(char *pc, t_varpc *svar)
{
	pc++;
	while (*pc != svar->ascii)
	{
		if (*pc == '0')
		{
			if (svar->flag_zero)
				return (0);
			svar->flag_zero = 1;
		}
		else if (ft_isdigit(*pc))
		{
			svar->length = ft_atoi_custom(pc);
			while (ft_isdigit(*pc))
				pc++;
			pc--;
		}
		else if (!ft_checkdoubleflag(*pc, svar))
			return (0);
		else if (!ft_checkprecision(&pc, svar))
			return (0);
		pc++;
	}
	return (1);
}

char	ft_checkstrpc_endok(char *pc)
{
	pc++;
	while (*pc == 32 || *pc == '+' || *pc == '-' || *pc == '.'
		|| *pc == '#' || ft_isdigit(*pc) || *pc == 'c'
		|| *pc == 's' || *pc == 'd' || *pc == 'i'
		|| *pc == 'u' || *pc == 'x' || *pc == 'X')
	{
		if (*pc == 'c' || *pc == 's' || *pc == 'd' || *pc == 'i'
			|| *pc == 'u' || *pc == 'x' || *pc == 'X')
			return (*pc);
		pc++;
	}
	return (0);
}
