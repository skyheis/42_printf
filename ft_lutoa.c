/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:37:59 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/24 23:54:26 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_lu_digits(long unsigned int n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		k++;
	}
	return (k);
}

char	*ft_lutoa(long unsigned int n)
{
	size_t	len_s;
	char	*str_nbr;

	str_nbr = (char *) malloc(((len_s = ft_lu_digits(n))) * sizeof(char));
	if (str_nbr == NULL)
		return (NULL);
	str_nbr[len_s--] = '\0';
	if (!n)
		str_nbr[len_s] = '0';
	while (n)
	{
		str_nbr[len_s--] = n % 10 + 48;
		n /= 10;
	}
	return (str_nbr);
}
