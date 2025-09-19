/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:42:12 by rparodi           #+#    #+#             */
/*   Updated: 2025/09/19 17:15:34 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

/**
 * @brief Write an output with format in the fd given in parameter
 *
 * @param fd file descriptor where the fd will be write
 * @param s The format string
 * @return The number of character write in the fd
 */
int		ft_dprintf(int fd, const char *s, ...);

/**
 * @brief Write an output with format in the stdout
 *
 * @param s The format string
 * @return The number of character write in the stdout
 */
int		ft_printf(const char *s, ...);

/**
 * @brief Write an output with the format in the fd given and the va_list
 *
 * @param fd file descriptor where the fd will be write
 * @param s The format string
 * @param args Arguments to pass to the format string
 * @return 
 */
int		ft_vdprintf(int fd, const char *s, va_list args);

#endif
