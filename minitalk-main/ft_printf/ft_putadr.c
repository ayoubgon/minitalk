/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:49:12 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/22 17:35:15 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putadr(unsigned long nbr, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr >= 16)
		ft_putadr(nbr / 16, len);
	*len += ft_putchar(hexa[nbr % 16]);
}
