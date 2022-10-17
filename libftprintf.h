/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:39 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/17 18:07:29 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_varpc
{
	char	ascii;
	int	length;
	int	flag_32;
	int	flag_plus;
	int	flag_sharp;
	int	flag_dash;
	int	flag_zero;
	int	flag_prec;
}	t_varpc;

t_varpc	*ft_svarnew(char ascii);
void	ft_svardel(t_varpc *svar);
void	ft_checkrulesconflict(t_varpc *svar);

#endif
