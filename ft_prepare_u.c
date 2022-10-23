/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:28:45 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/23 15:34:22 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_fill_u(t_varpc *svar, char *utoa_var, char *u, ssize_t ua_len)
{
	if (svar->flag_dash)
	{
		while (svar->prec > ua_len++)
			*u++ = '0';
		u += ft_strlcpy(u, utoa_var, ua_len);
		while ((ssize_t) svar->length > ua_len++)
			*u++ = ' ';
	}
	else
	{
		if (svar->prec == -1)
			svar->length -= ua_len;
		while ((ssize_t) svar->length-- > svar->prec + 1)
			*u++ = ' ';
		while (svar->prec > ua_len++)
			*u++ = '0';
		u += ft_strlcpy(u, utoa_var, ua_len);
	}
}

int	ft_checkconflict_u(t_varpc *svar)
{
	if (svar->flag_32 || svar->flag_sharp || svar->flag_plus)
		return (0);
	if (svar->flag_zero)
	{
		if (svar->flag_dash || svar->prec != -1)
			return (0);
	}
	return (1);
}

void	ft_adjust_usize(t_varpc *svar, size_t *u_size)
{
	if (svar->length > *u_size || svar->prec > (ssize_t)(*u_size))
	{
		if ((ssize_t) svar->length > svar->prec)
			*u_size = svar->length;
		else
			*u_size = (ssize_t) svar->prec;
	}
}

char	*ft_prepare_u(t_varpc *svar, unsigned int u_var)
{
	char	*u;
	char	*utoa_var;
	size_t	u_size;
	size_t	utoa_orig_size;

	if (!ft_checkconflict_u(svar))
		return (0);
	utoa_var = ft_itoa((int) u_var);
	utoa_orig_size = ft_strlen(utoa_var);
	u_size = utoa_orig_size;
	ft_adjust_usize(svar, &u_size);
	u = (char *) malloc((u_size + 1) * sizeof(char));
	if (!u)
		return (0);
	u[u_size] = '\0';
	ft_fill_u(svar, utoa_var, u, (ssize_t) utoa_orig_size);
	u = ft_idu_handle_zero(svar, u, utoa_var[0]);
	free(utoa_var);
	return (u);
}