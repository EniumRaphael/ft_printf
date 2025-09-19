/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:44:34 by rparodi           #+#    #+#             */
/*   Updated: 2025/09/19 17:17:12 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static int	print_buff(int fd, const char *s, size_t start, size_t end)
{
	return (write(fd, s + start, (end - start)));
}

static int	flag_managenent(int fd, char flag, va_list args)
{
	size_t			i;
	const t_format	flags[] = {
	{'c', flag_c},
	{'d', flag_i},
	{'p', flag_p},
	{'u', flag_u},
	{'%', flag_percent},
	{'i', flag_i},
	{'s', flag_s},
	{'x', flag_x},
	{'X', flag_x_maj},
	};

	i = 0;
	while (flags[i].character)
	{
		if (flags[i].character == flag)
			return (flags[i].function(args, fd));
		i++;
	}
	return (-1);
}

int	ft_vdprintf(int fd, const char *s, va_list args)
{
	size_t	i;
	size_t	temp;
	int		to_ret;

	if (!s)
		return (-1);
	i = 0;
	to_ret = 0;
	temp = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			to_ret += print_buff(fd, s, temp, i);
			if (s[++i])
				to_ret += flag_managenent(fd, s[i], args);
			else
				return (write(1, &s[i - 1], 1) + to_ret);
			temp = i + 1;
		}
		i++;
	}
	to_ret += print_buff(fd, s, temp, i);
	return (to_ret);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	int		to_ret;
	va_list	args;

	va_start(args, s);
	to_ret = ft_vdprintf(fd, s, args);
	va_end(args);
	return (to_ret);
}

int	ft_printf(const char *s, ...)
{
	int		to_ret;
	va_list	args;

	va_start(args, s);
	to_ret = ft_vdprintf(1, s, args);
	va_end(args);
	return (to_ret);
}
