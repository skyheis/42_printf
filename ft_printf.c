/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:08:13 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/23 21:20:33 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pchandle(t_varpc **svar, va_list vargo)
{
	char	*toprint;
	int	ret_pf;

	if ((*svar)->ascii == 'c')
		toprint = ft_prepare_c((*svar), (char) va_arg(vargo, int));
	else if ((*svar)->ascii == 's')
		toprint = ft_prepare_s((*svar), va_arg(vargo, char *));
	else if ((*svar)->ascii == 'i' || (*svar)->ascii == 'd')
		toprint = ft_prepare_id((*svar), va_arg(vargo, int));
	else if ((*svar)->ascii == 'u')
		toprint = ft_prepare_u((*svar), va_arg(vargo, unsigned int));
	else if ((*svar)->ascii == 'x' && (*svar)->ascii == 'X')
		toprint = ft_prepare_x((*svar), va_arg(vargo, unsigned int));
	else if ((*svar)->ascii == 'p')
		toprint = ft_prepare_p((*svar), va_arg(vargo, void *));
	ft_putstr_fd(toprint, 1);
	ret_pf = ft_strlen(toprint);
	(*svar) = (*svar)->next;
	free(toprint);
	return (ret_pf);
}

int	ft_handleprintf(t_varpc *svar, va_list vargo, char *str)
{
	int	k;
	int	ret_pf;

	k = 0;
	ret_pf = 0;
	while (str[k] != '\0')
	{
		if (str[k] != '%')
		{
			write(1, &str[k++], 1);
			ret_pf++;
		}
		else if (str[k] == '%' && str[k + 1] == '%')
		{
			write(1, "%%", 2);
			ret_pf += 2;
			k += 2;
		}
		else
		{
			ret_pf += ft_pchandle(&svar, vargo);
			k += ft_strpclen(&str[k]) + 1;
		}
	}
	return (ret_pf);
}

t_varpc	*ft_checkprintfstr(const char *str)
{
	int	k;
	t_varpc	*svar;

	k = 0;
	svar = NULL;
	while (str[k] != '\0')
	{
		if (str[k] == '%' && str[k + 1] == '%')
			k += 2;
		else if (str[k] == '%')
		{
			//if (!svar)
			//	svar = ft_checkstrpc_endok((char *)&str[k]);
			if (!ft_pcfinded(&svar, (char *) &str[k]))
				return (0);
			k++;
		}
		else
			k++;
	}
	return (svar);
}

int	ft_printf(const char *str, ...)
{
	int	ret_pf;
	va_list	vargo;
	t_varpc	*svar;

	if (!str)
		return (0);
	svar = ft_checkprintfstr(str);
	if (!svar)
		return (0);
	va_start(vargo, str);
	ret_pf = ft_handleprintf(svar, vargo, (char *) str);
	ft_svarclear(&svar);
	va_end(vargo);
	return (ret_pf);
}
