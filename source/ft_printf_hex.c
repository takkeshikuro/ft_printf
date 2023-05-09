/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:21:56 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/12/03 16:49:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_hex(unsigned int n)
{
	int	comp;

	comp = 1;
	while (n >= 16)
	{
		n = n / 16;
		comp++;
	}
	return (comp);
}

int	ft_putnbr_hexa_min(int n)
{
	int			i;
	char		*base_hexa;
	long int	nbr;

	nbr = n;
	base_hexa = "0123456789abcdef";
	i = ft_strlen(base_hexa);
	if (nbr < 0)
		nbr = (unsigned int)nbr;
	if (nbr >= i)
	{
		ft_putnbr_hexa_min(((unsigned int)nbr) / i);
		ft_putnbr_hexa_min(((unsigned int)nbr) % i);
	}
	if (nbr < i)
		ft_putchar(base_hexa[nbr]);
	return (count_hex(n));
}

int	ft_putnbr_hexa_maj(int n)
{
	int			i;
	char		*base_hexa;
	long int	nbr;

	nbr = n;
	base_hexa = "0123456789ABCDEF";
	i = ft_strlen(base_hexa);
	if (nbr < 0)
		nbr = (unsigned int)nbr;
	if (nbr >= i)
	{
		ft_putnbr_hexa_maj(((unsigned int)nbr) / i);
		ft_putnbr_hexa_maj(((unsigned int)nbr) % i);
	}
	if (nbr < i)
		ft_putchar(base_hexa[nbr]);
	return (count_hex(n));
}
