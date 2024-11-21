/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:15 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/11/21 04:03:20 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int	count;
	va_start(args, frmt);
	char	c;
	char 	*s;
	int	nbr;
	count = 0;
	
	while (*frmt)
	{
		if (*frmt == '%' && *(frmt + 1))
		{
			frmt++;
			if (*frmt == 'c')
			{
				c = va_arg(args, int);
				count += ft_putchar(c);
			}
			else if (*frmt == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					count += ft_putstr("(null)");
				else
					count += ft_putstr(s);
			}
			else if (*frmt == 'd')
			{
				nbr = va_arg(args, int);
				count += ft_putnbr(nbr);
			}
			else if (*frmt == 'i')
			{
				nbr = va_arg(args, int);
				count += ft_putnbr(nbr);
			}
		}
		else
			count += ft_putchar(*frmt);
		frmt++;
	}
	va_end(args);
	return count;
}

//
//int main()
//{
//	ft_printf("Hello %s!\n", "world"); 
//	ft_printf("Char: %c, String: %s\n", 'A', "Test"); 
//	ft_printf("%s is NULL\n", NULL); 
//	ft_printf("Positive: %d\n", 123);
//	ft_printf("Negative: %d\n", -456);
//	ft_printf("Zero: %d\n", 0);
//	ft_printf("Edge: %d\n", -2147483648);
//
//	printf("Hello %s!\n", "world");
//	printf("Char: %c, String: %s\n", 'A', "Test"); 
//	printf("%s is NULL\n", NULL); 
//	ft_printf("Positive: %d\n", 123);
//	printf("Negative: %d\n", -456);
//	printf("Zero: %d\n", 0);
//	printf("Edge: %d\n", -2147483648);
//}
//