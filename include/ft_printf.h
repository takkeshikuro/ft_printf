/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:03:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/12/02 17:57:00 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_printf(const char *format, ...);
int					while_str(const char *s, va_list arg);
int					global_convert(va_list arg, char c);
int					just_p(va_list arg);
unsigned long int	ft_ptr(unsigned long int n);
int					count_hex(unsigned int n);
int					count_hex2(unsigned long int n);
int					count_dec(unsigned int n);
int					ft_putchar(char c);
int					ft_putnbr(int n);
int					ft_unsignednbr(unsigned int n);
int					ft_putnbr_hexa_min(int n);
int					ft_putnbr_hexa_maj(int n);
int					ft_printstr(char *str);
int					ft_strlen(const char *str);
#endif