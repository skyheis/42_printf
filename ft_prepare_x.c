/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:55:30 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/24 16:14:48 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_x_var(t_varpc *svar, unsigned int x_var,
		char *x_spot, ssize_t x_orig_size)
{
	int	c;

	if (!x_var)
		x_spot[x_orig_size - 1] = '0';
	if (svar->ascii == 'x')
	{
		while (x_orig_size)
		{
			c = x_var % 16;
			x_var /= 16;
			x_spot[x_orig_size - 1] = "0123456789abcdef"[c];
			x_orig_size--;
		}
	}
	else
	{
		while (x_orig_size)
		{
			c = x_var % 16;
			x_var /= 16;
			x_spot[x_orig_size - 1] = "0123456789ABCDEF"[c];
			x_orig_size--;
		}
	}
}

void	ft_fill_x_0(t_varpc *svar, unsigned int x_var,
		char *x, ssize_t x_orig_size)
{
	ssize_t	k;

	k = 0;
	if (svar->flag_sharp)
	{
		x[k++] = '0';
		if (svar->ascii == 'x')
			x[k++] = 'x';
		else
			x[k++] = 'X';
	}
	while (svar->prec-- > x_orig_size)
		x[k++] = '0';
	ft_put_x_var(svar, x_var, &x[k], x_orig_size);
	k += x_orig_size;
	while (svar->length > (size_t) k)
		x[k++] = ' ';
}

void	ft_fill_x_1(t_varpc *svar, unsigned int x_var,
		char *x, ssize_t x_orig_size)
{
	ssize_t	k;
	ssize_t	set;

	k = 0;
	set = 0;
	while (svar->prec - set > x_orig_size)
		set++;
	if (svar->flag_sharp)
		set += 2;
	while ((ssize_t) svar->length-- > x_orig_size + set)
		x[k++] = ' ';
	if (svar->flag_sharp)
	{
		x[k++] = '0';
		if (svar->ascii == 'x')
			x[k++] = 'x';
		else
			x[k++] = 'X';
	}
	while (svar->prec-- > x_orig_size)
		x[k++] = '0';
	ft_put_x_var(svar, x_var, &x[k], x_orig_size);
}

void	ft_adjust_xsize(t_varpc *svar, unsigned int x_var, size_t *x_size)
{
	if (svar->prec > (ssize_t)(*x_size))
		*x_size = (ssize_t) svar->prec;
	if (svar->flag_sharp && x_var != 0)
		*x_size += 2;
	if (svar->length > *x_size)
		*x_size = svar->length;
}

char	*ft_prepare_x(t_varpc *svar, unsigned int x_var)
{
	char	*x;
	size_t	x_size;
	size_t	x_orig_size;

	if (svar->flag_32 || svar->flag_plus
		|| (svar->flag_zero && svar->flag_dash)
		|| (svar->flag_zero && svar->prec != -1))
		return (0);
	x_size = ft_get_x_size(x_var);
	x_orig_size = x_size;
	ft_adjust_xsize(svar, x_var, &x_size);
	x = (char *) malloc((x_size + 1) * sizeof(char));
	if (!x)
		return (0);
	x[x_size] = '\0';
	if (svar->flag_dash)
		ft_fill_x_0(svar, x_var, x, x_orig_size);
	else
		ft_fill_x_1(svar, x_var, x, x_orig_size);
	x = ft_x_handle_zero(svar, x, x_size, x_orig_size);
	return (x);
}
