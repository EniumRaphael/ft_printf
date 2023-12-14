/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:27:44 by rparodi           #+#    #+#             */
/*   Updated: 2023/12/14 18:17:22 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_args(char c, va_list args, int *ret_value)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), ret_value);
	else if (c == 's')
		ft_putstr((char *)va_arg(args, char *), ret_value);
	else if (c == 'i' || c == 'd')
		ft_putnbr((int)va_arg(args, int), ret_value);
	else if (c == '%')
		ft_putchar('%', ret_value);
	else if (c == 'u')
		ft_putnbr_unsigned((unsigned int)va_arg(args, unsigned int), ret_value);
	else if (c == 'x')
		ft_putnbr_base((unsigned int)va_arg(args, unsigned int), \
				"0123456789abcdef", ret_value, c);
	else if (c == 'X')
		ft_putnbr_base((unsigned int)va_arg(args, unsigned int), \
				"0123456789ABCDEF", ret_value, c);
	else if (c == 'p')
		ft_putnbr_base((unsigned long long)va_arg(args, unsigned long long), \
				"0123456789abcdef", ret_value, c);
	va_end(args);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;
	char	*str;
	int		ret_value;

	ret_value = 0;
	str = ft_strdup(s);
	va_start(args, s);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_check_args(str[i + 1], args, &ret_value);
			i++;
		}
		else
			ft_putchar(str[i], &ret_value);
		i++;
	}
	free(str);
	return (ret_value);
}
