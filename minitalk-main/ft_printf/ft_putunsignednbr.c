/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:49:07 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/22 17:16:42 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putunsignednbr(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putunsignednbr((nb / 10), len);
		nb = nb % 10;
	}
	if (nb < 10)
		*len += ft_putchar(nb + 48);
}
