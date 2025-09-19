/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:42:12 by rparodi           #+#    #+#             */
/*   Updated: 2025/09/19 15:53:37 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

typedef int	(*t_func)(va_list, int fd);

typedef struct s_format
{
	char	character;
	t_func	function;
}			t_format;

size_t	ft_strlen(const char *str);
void	ft_putnbr_base(int fd, uint64_t nbr, char *base, int *to_ret);
char	*itoa_base(uint64_t nbr, char *base);
int		flag_c(va_list args, int fd);
int		ft_dprintf(int fd, const char *s, ...);
int		ft_printf(const char *s, ...);
int		flag_i(va_list args, int fd);
int		flag_p(va_list args, int fd);
int		flag_percent(va_list args, int fd);
int		flag_s(va_list args, int fd);
int		flag_u(va_list args, int fd);
int		flag_x(va_list args, int fd);
int		flag_x_maj(va_list args, int fd);

#endif
