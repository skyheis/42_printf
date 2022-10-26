/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnewpc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:39:14 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/26 15:23:21 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*void	ft_svarprint(t_varpc *lol)
{
        printf("char %c\n", lol->ascii);
        printf("len  %lu\n", lol->length);
        printf("prec %li\n", lol->prec);
        printf("32   %i\n", lol->flag_32);
        printf("plus %i\n", lol->flag_plus);
        printf("shar %i\n", lol->flag_sharp);
        printf("dash %i\n", lol->flag_dash);
        printf("zero %i\n", lol->flag_zero);
}*/
int	ft_fill_id_1_32(t_varpc *svar, char *itoa_var, char *id, ssize_t ia_len)
{
	int	k;

	k = 0;
	if (svar->prec == 0 && *itoa_var == '0')
	{
		while ((ssize_t) svar->length-- > svar->prec)
			id[k++] = ' ';
	}
	else if (svar->prec == 0)
	{
		while ((ssize_t) svar->length-- > ia_len + 1)
			id[k++] = ' ';
	}
	else
	{
		while ((ssize_t)svar->length-- > svar->prec + 1)
			id[k++] = ' ';
	}
	return (k);
}

int	ft_strpclen(char *pc)
{
	int	k;

	k = 1;
	while (pc[k] == 32 || pc[k] == '+' || pc[k] == '-' || pc[k] == '.'
		|| pc[k] == '#' || ft_isdigit(pc[k]) || pc[k] == 'c'
		|| pc[k] == 's' || pc[k] == 'd' || pc[k] == 'i'
		|| pc[k] == 'u' || pc[k] == 'x' || pc[k] == 'x' || pc[k] == 'p')
	{
		if (pc[k] == 'c' || pc[k] == 's' || pc[k] == 'd' || pc[k] == 'i'
			|| pc[k] == 'u' || pc[k] == 'x' || pc[k] == 'x' || pc[k] == 'p')
			return (k);
		k++;
	}
	return (k);
}

int	ft_pcfinded(t_varpc **svar, char *pc)
{
	t_varpc	*newsvar;

	newsvar = ft_checkstrpc_endok(pc);
	if (newsvar)
	{
		if (!ft_checkstrpc_gook(pc, newsvar))
		{
			free(newsvar);
			return (0);
		}
		ft_svaradd_back(svar, newsvar);
	}
	else
		return (0);
	return (1);
}
