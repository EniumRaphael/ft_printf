/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:49:02 by rparodi           #+#    #+#             */
/*   Updated: 2025/09/19 15:39:41 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int	flag_c(va_list args, int fd)
{
	const char	character = va_arg(args, int);

	return (write(fd, &character, 1));
}

int	flag_s(va_list args, int fd)
{
	const char	*string = va_arg(args, char *);

	if (string == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, string, ft_strlen(string)));
}

int	flag_percent(va_list args, int fd)
{
	(void)args;
	return (write(fd, "%", 1));
}
