/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:41:38 by ggiannit          #+#    #+#             */
/*   Updated: 2022/10/24 23:45:37 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*int main(void)
{
   char* p;

   p = NULL;
   printf("%s", p);
   return 0;
}*/

int	main(void)
{
//	char *null_str;
	int	ciao;

	ciao = 42;
//	null_str = NULL;
//	printf("%lu\n", (long unsigned int)-1);
	ft_printf("%u\n", (unsigned int)4294967295);
	ft_printf("This %p is even stranger", (void *)-1);
	ft_printf("This %p is even stranger", (void *)(long int)ciao);
//	ft_printf("%s daje", null_str);
	/*ft_printf("this is safe! %s %%\n", "amazing!");
	ft_printf("this is safe!\n");
	ft_printf("%c %c %10s\n", 'a','\0',"oki");
        ft_printf("'%u'\n", 42);
        ft_printf("'%8u' %-+6i \n", 42, -42);
        ft_printf("'%.8u'\n", 42);
        ft_printf("'%-4.8u'\n", 42);
        ft_printf("'%-8.4u'\n", 42);
        ft_printf("'%-.5u'\n", 42);
        ft_printf("'%-+10i'\n", 42);
	ft_printf("%-8.4u%i' %x %x%%%-10.6s\n %-10i %%%%%%%c", 12, 42, 42, 42, "daleee!", 1, 'C');
	*/
}
