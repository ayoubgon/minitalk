/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:47:54 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/22 17:35:44 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_putfun(va_list arg, char s)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (s == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (s == 'p')
	{
		len += write(1, "0x", 2);
		ft_putadr(va_arg(arg, unsigned long), &len);
	}
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(arg, int), &len);
	else if (s == 'u')
		ft_putunsignednbr(va_arg(arg, unsigned int), &len);
	else if (s == 'x')
		ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef", &len);
	else if (s == 'X')
		ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF", &len);
	else if (s == '%')
		len += write(1, "%", 1);
	else
		len += write(1, &s, 1);
	return (len);
}
