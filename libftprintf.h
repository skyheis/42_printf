/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:39 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/19 21:37:01 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_varpc
{
	char	ascii;
	size_t	length;
	long long int	prec;
	int	flag_32;
	int	flag_plus;
	int	flag_sharp;
	int	flag_dash;
	int	flag_zero;
}	t_varpc;

t_varpc	*ft_svarnew(char ascii);
void	ft_svardel(t_varpc *svar);
size_t	ft_atoi_custom(const char *pc);
int	ft_checkdoubleflag(char pcv, t_varpc *svar);
int	ft_checkprecision(char **pc, t_varpc *svar);
int	ft_checkstrpc_gook(char *pc, t_varpc *svar);
char	ft_checkstrpc_endok(char *pc);
t_varpc	*ft_pcfinded(char *pc);
void	ft_fill_c(t_varpc *svar, char c_var, char *c, size_t c_size);
char	*ft_prepare_c(t_varpc *svar, char c_var);
void	ft_fill_s(t_varpc *svar, char *s_var, char *s, size_t s_size);
char	*ft_prepare_s(t_varpc *svar, char *s_var);

//void	ft_checkrulesconflict(t_varpc *svar);
char	*ft_testino(char *pc);
void	ft_svarprint(t_varpc *lol);

#endif
