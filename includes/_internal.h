/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _internal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:15:50 by rparodi           #+#    #+#             */
/*   Updated: 2025/09/19 17:25:25 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERNAL_H
# define _INTERNAL_H

# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

typedef int	(*t_func)(va_list, int fd);

typedef struct s_format
{
	char	character;
	t_func	function;
}			t_format;

/**
 * @brief Computes the length of a string.
 *
 * @param s The input string.
 *
 * @return The number of characters in the string `s`.
 */
size_t	ft_strlen(const char *str);

char	*itoa_base(uint64_t nbr, char *base);

int		flag_c(va_list args, int fd);

int		flag_i(va_list args, int fd);

int		flag_p(va_list args, int fd);

int		flag_percent(va_list args, int fd);

int		flag_s(va_list args, int fd);

int		flag_u(va_list args, int fd);

int		flag_x(va_list args, int fd);

int		flag_x_maj(va_list args, int fd);

#endif
