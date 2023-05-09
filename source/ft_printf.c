/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:50:02 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/12/03 17:56:04 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	just_p(va_list arg)
{
	unsigned long int	tmp;

	tmp = va_arg(arg, unsigned long int);
	if (!tmp)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_ptr(tmp) + 2);
}

int	global_convert(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar((int)va_arg(arg, int)));
	else if (c == 's')
		return (ft_printstr((char *)va_arg(arg, char *)));
	else if (c == 'p')
		return (just_p(arg));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr((int)va_arg(arg, int)));
	else if (c == 'u')
		return (ft_unsignednbr((unsigned int)va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hexa_min((int)va_arg(arg, int)));
	else if (c == 'X')
		return (ft_putnbr_hexa_maj((int)va_arg(arg, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	while_str(const char *s, va_list arg)
{
	int	i;
	int	j;
	int	stock;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	stock = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = global_convert(arg, s[i + 1]);
			if (len == -1)
				return (-1);
			i++;
			j += 2;
			stock += len;
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	return (i - j + stock);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, format);
	len = while_str(format, arg);
	if (len == -1)
		return (-1);
	va_end(arg);
	return (len);
}

/*  #include <stdio.h>

int	main(void)
{
	//void			*ko;
	char			*str;
	int				i;

	//ko = NULL;
	str = "takeshi";

	i = -42;
	printf("%d\n", ft_printf("ok, %s, %p, %X, %%%x%%\n", str, str, i, i));
	printf("%d\n", printf("ok, %s, %p, %X, %%%x%%\n", str, str, i, i));
	//printf("%d\n", ft_printf("%p\n", str));
	//printf("%d\n", ft_printf("okok %y\n"));
	//printf("%d\n", printf("%p\n", ko));
	//printf("\n%
	//printf("%d\n", 	ft_printf("%s\n", str));
	//ft_printf("%s\n", str);
} */