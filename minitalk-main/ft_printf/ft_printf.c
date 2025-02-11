/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:46:50 by adehbi            #+#    #+#             */
/*   Updated: 2024/12/03 19:56:14 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	va_start(arg, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			len += ft_putfun(arg, str[i]);
		}
		else if (str[i] != '%')
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
#include <stdio.h>

int main()
{
	int k;
	k = -42;
	int i = ft_printf("%x\n",k);
	printf("\n");
	int j = printf("%x\n",k);
	printf("\n dyaleq %d | sys %d ",i,j);
	return 0;
}