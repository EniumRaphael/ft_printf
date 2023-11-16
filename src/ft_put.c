/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:13:14 by rparodi           #+#    #+#             */
/*   Updated: 2023/11/16 12:14:35 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ret_value)
{
	write(1, &c, 1);
	(*ret_value)++;
}

void	ft_putnbr(int nb, int *ret_value)
{
	if (nb < 0)
	{
		if (nb == INT_MIN)
		{
			write(1, "-2147483648", 11);
			*ret_value += 11;
			return ;
		}
		nb = -nb;
		ft_putchar('-', ret_value);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, ret_value);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, ret_value);
}

void	ft_putnbr_base(\
		unsigned long long nbr, char *base, int *ret_value, char c)
{
	if (c == 'p')
	{
		if (nbr != 0)
			ft_putstr("0x", ret_value);
		if (nbr == 0)
		{
			ft_putstr("(nil)", ret_value);
			return ;
		}
		c++;
	}
	if (c != 'p')
	{
		if (nbr >= 16)
			ft_putnbr_base(nbr / 16, base, ret_value, c);
		ft_putchar(base[nbr % 16], ret_value);
	}
}

void	ft_putnbr_unsigned(unsigned int nb, int *ret_value)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, ret_value);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, ret_value);
}

void	ft_putstr(char *str, int *ret_value)
{
	if (!str)
		*ret_value += write(1, "(null)", 6);
	else
		*ret_value += write(1, str, ft_strlen(str));
}
