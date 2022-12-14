/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:49:31 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/09 15:27:21 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_putnbr_fd(int n, int fd)
{
	size_t	k;
	char	tmp[11];

	k = 9;
	tmp[10] = '\0';
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		while (n)
		{
			tmp[k--] = (n % 10 + 48);
			n /= 10;
		}
		k++;
		while (tmp[k] != '\0')
			write(fd, &tmp[k++], 1);
	}
}
