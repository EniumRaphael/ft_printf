/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:00:27 by rparodi           #+#    #+#             */
/*   Updated: 2025/09/19 17:19:45 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	flag_p(va_list args, int fd)
{
	char		*to_print;
	int			to_ret;
	uint64_t	number;

	number = va_arg(args, unsigned long long);
	to_ret = 0;
	if (number != 0)
		to_ret += write(fd, "0x", 2);
	else if (number == 0)
		return (write(fd, "(nil)", 5));
	to_print = itoa_base(number, "0123456789abcdef");
	to_ret += write(fd, to_print, ft_strlen(to_print));
	free(to_print);
	return (to_ret);
}

int	flag_x_maj(va_list args, int fd)
{
	char			*to_print;
	int				to_ret;
	unsigned int	number;

	number = va_arg(args, unsigned int);
	to_print = itoa_base(number, "0123456789ABCDEF");
	to_ret = write(fd, to_print, ft_strlen(to_print));
	free(to_print);
	return (to_ret);
}

int	flag_x(va_list args, int fd)
{
	char			*to_print;
	int				to_ret;
	unsigned int	number;

	number = va_arg(args, unsigned int);
	to_print = itoa_base(number, "0123456789abcdef");
	to_ret = write(fd, to_print, ft_strlen(to_print));
	free(to_print);
	return (to_ret);
}

int	flag_u(va_list args, int fd)
{
	char			*to_print;
	int				to_ret;
	unsigned int	number;

	to_ret = 0;
	number = va_arg(args, unsigned int);
	to_print = itoa_base(number, "0123456789");
	to_ret = write(fd, to_print, ft_strlen(to_print));
	free(to_print);
	return (to_ret);
}

int	flag_i(va_list args, int fd)
{
	char	*to_print;
	int		number;
	int		to_ret;

	to_ret = 0;
	number = va_arg(args, int);
	if (number < 0)
	{
		if (number == INT_MIN)
			return (write(1, "-2147483648", 11));
		number = -number;
		to_ret += write(1, "-", 1);
	}
	to_print = itoa_base(number, "0123456789");
	to_ret += write(fd, to_print, ft_strlen(to_print));
	free(to_print);
	return (to_ret);
}
