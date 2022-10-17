/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:48:32 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/17 20:58:54 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// c
int	main(void)
{
	printf("test '%0i'\n", 'c');
	printf("test '%.10i'\n", 'c');
	printf("test '%-i'\n", 'c');
//	printf("test '%#i'\n", 'c');
	printf("test '% i'\n", 'c');
	printf("test '%+i'\n", 'c');
	
//	printf("test '%0.10i'\n", 'c');
	printf("test '%0++++++++++++++++++++++++++++++++++++++ ---++++                                                 --i'\n", 'c');
}

// S 
/*int	main(void)
{
	char *c = "abcdefghijklmnopq";

//	printf("test '%0s'\n", c);
	printf("test '%-12.10s'\n", c);
	printf("test '%-s'\n", c);
//	printf("test '%#s'\n", c);
//	printf("test '% s'\n", c);
//	printf("test '%+s'\n", c);
}*/

// c
/*int	main(void)
{
//	printf("test '%0c'\n", 'c');
//	printf("test '%.10c'\n", 'c');
	printf("test '%-c'\n", 'c');
//	printf("test '%#c'\n", 'c');
//	printf("test '% c'\n", 'c');
//	printf("test '%+c'\n", 'c');
}*/

// P 
/*int	main(void)
{
	char *c = "abcdefghijklmnopq";

//	printf("test '%0p'\n", c);
//	printf("test '%.10p'\n", c);
	printf("test '%-p'\n", c);
//	printf("test '%#p'\n", c);
//	printf("test '% p'\n", c);
//	printf("test '%+p'\n", c);
}*/
