/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:48:37 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/22 17:13:04 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		*len += ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		*len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr((nb / 10), len);
		nb = nb % 10;
	}
	if (nb < 10)
		*len += ft_putchar(nb + 48);
}
