/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setrules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:41:59 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/17 18:51:23 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//dare indirizzo del % (tipo &str[k])
t_varpc	*ft_setrules(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0' || str[k] 
