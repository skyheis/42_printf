/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:39 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/21 01:12:39 by ggiannit         ###   ########.fr       */
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
	ssize_t	prec;
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
int	ft_checkconflict_id(t_varpc *svar);
void	ft_adjust_idsize(t_varpc *svar, size_t *id_size, size_t itoa_orig_size, char itoa_0);
char	*ft_prepare_id(t_varpc *svar, int id_var);
void	ft_fill_id_0(t_varpc *svar, char *itoa_var, char *id, ssize_t ia_len);
void	ft_fill_id_1(t_varpc *svar, char *itoa_var, char *id, ssize_t ia_len);
char	*ft_id_handle_zero(t_varpc *svar, char *id, char itoa_0);
void	ft_fill_u(t_varpc *svar, char *itoa_var, char *id, ssize_t ua_len);
int	ft_checkconflict_u(t_varpc *svar);
void    ft_adjust_usize(t_varpc *svar, size_t *u_size, size_t utoa_orig_size);
char	*ft_prepare_u(t_varpc *svar, int u_var);

//void	ft_checkrulesconflict(t_varpc *svar);
char	*ft_testino(char *pc);
void	ft_svarprint(t_varpc *lol);

#endif
