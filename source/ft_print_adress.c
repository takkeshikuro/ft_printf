/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:33:58 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/12/02 21:00:00 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count_hex2(unsigned long int n)
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

unsigned long int	ft_ptr(unsigned long int n)
{
	unsigned long int	i;
	char				*base_hexa;
	unsigned long int	nbr;

	nbr = n;
	base_hexa = "0123456789abcdef";
	i = ft_strlen(base_hexa);
	if (nbr >= i)
	{
		ft_ptr((nbr) / i);
		ft_ptr((nbr) % i);
	}
	else if (nbr >= -i)
	{
		ft_ptr((nbr) / i);
		ft_ptr((nbr) % i);
	}
	if (nbr < i)
		ft_putchar(base_hexa[nbr]);
	return (count_hex2(n));
}
