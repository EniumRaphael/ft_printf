/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:59:10 by rparodi           #+#    #+#             */
/*   Updated: 2023/11/16 15:10:41 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define UINT_MAX 4294967295
# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		ft_printf(const char *str, ...);
int		ft_check_args(char c, va_list args, int *ret_value);
void	ft_putnbr_unsigned(unsigned int nb, int *ret_value);
void	ft_putnbr(int nb, int *ret_value);
void	ft_putchar(char c, int *ret_value);
void	ft_putstr(char *str, int *ret_value);
void	ft_putnbr_base(\
		unsigned long long nbr, char *base, int *ret_value, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif
