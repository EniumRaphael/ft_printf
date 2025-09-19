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

/**
 * @brief Function to convert a number to an other base
 *
 * @param nbr number to convert
 * @param base base to convert in
 * @return the string with the number converted
 */
char	*itoa_base(uint64_t nbr, char *base);

/**
 * @brief Function to handle the flag c in printf's function
 *
 * @param args list of arguments
 * @param fd file descriptor
 * @return The number of character write in the fd (always 1)
 */
int		flag_c(va_list args, int fd);

/**
 * @brief Function to handle the flag i in printf's function
 *
 * @param args list of arguments
 * @param fd file descriptor
 * @return The number of character write in the fd
 */
int		flag_i(va_list args, int fd);

/**
 * @brief Function to handle the flag p in printf's function
 *
 * @param args list of arguments
 * @param fd file descriptor
 * @return The number of character write in the fd
 */
int		flag_p(va_list args, int fd);

int		flag_percent(va_list args, int fd);

int		flag_s(va_list args, int fd);

int		flag_u(va_list args, int fd);

int		flag_x(va_list args, int fd);

int		flag_x_maj(va_list args, int fd);

#endif
