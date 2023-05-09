/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:30:25 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/30 18:47:46 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count_dec(unsigned int n)
{
	int	comp;

	comp = 1;
	while (n >= 10)
	{
		n = n / 10;
		comp++;
	}
	return (comp);
}

int	ft_unsignednbr(unsigned int n)
{
	unsigned int	nb;

	nb = n;
	if (nb > 9)
	{
		ft_unsignednbr(nb / 10);
		ft_unsignednbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
	return (count_dec(n));
}

int	ft_putnbr(int n)
{
	int		nb;
	int		negatif;

	negatif = 0;
	nb = n;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		ft_putchar('-');
		negatif++;
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
	return (count_dec(nb) + negatif);
}
