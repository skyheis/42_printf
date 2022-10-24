/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:41 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/24 17:10:13 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isa_c(t_varpc **svar, char c_var)
{
	char    *toprint;
	int	flago;

	toprint = ft_prepare_c((*svar), (char) c_var);
	flago = ft_putstr_fd(toprint, 1);
	if (c_var == '\0')
	{
		ft_putchar_fd('\0', 1);
		flago++;
	}
	(*svar) = (*svar)->next;
	free(toprint);
	return (flago);
}

int	ft_isa_s(t_varpc **svar, char *s_var)
{
	char    *toprint;
	int	flago;
 
	if (!s_var)
		flago = ft_putstr_fd("(null)", 1);
	else
	{
		toprint = ft_prepare_s((*svar), s_var);
		flago = ft_putstr_fd(toprint, 1);
		free(toprint);
	}
	(*svar) = (*svar)->next;
	return (flago);
}

int	ft_isa_p(t_varpc **svar, void *p_var)
{
	char    *toprint;
	int	flago;
 
	if (!p_var)
		flago = ft_putstr_fd("(nil)", 1);
	else
	{
		toprint = ft_prepare_p((*svar), p_var);
		flago = ft_putstr_fd(toprint, 1);
		free(toprint);
	}
	(*svar) = (*svar)->next;
	return (flago);
}

int	ft_isa_id(t_varpc **svar, int id_var)
{
	char    *toprint;
	int	flago;
 
	toprint = ft_prepare_id((*svar), id_var);
	flago = ft_putstr_fd(toprint, 1);
	free(toprint);
	(*svar) = (*svar)->next;
	return (flago);
}

int	ft_isa_ux(t_varpc **svar, unsigned int ux_var)
{
	char    *toprint;
	int	flago;
 
	if ((*svar)->ascii == 'u')
		toprint = ft_prepare_u((*svar), ux_var);
	else
		toprint = ft_prepare_x((*svar), ux_var);
	flago = ft_putstr_fd(toprint, 1);
	free(toprint);
	(*svar) = (*svar)->next;
	return (flago);
}
