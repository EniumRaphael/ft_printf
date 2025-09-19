/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:34:52 by rparodi           #+#    #+#             */
/*   Updated: 2025/09/19 16:45:11 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

static size_t	ft_nbrlen(u_int64_t nbr, size_t base_len)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*to_return;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(1));
	total = nmemb * size;
	if (total / nmemb != size && total / size != nmemb)
		return (NULL);
	to_return = (char *)malloc(total);
	if (to_return == NULL)
		to_return = NULL;
	else
		ft_memset(to_return, 0, nmemb * size);
	return (to_return);
}

char	*itoa_base(u_int64_t nbr, char *base)
{
	size_t	base_len;
	size_t	nbr_len;
	char	*result;
	int		i;

	if (!base)
		return (NULL);
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (NULL);
	nbr_len = ft_nbrlen(nbr, base_len);
	result = malloc(sizeof(char) * (nbr_len + 1));
	if (!result)
		return (NULL);
	i = nbr_len - 1;
	if (nbr == 0)
		result[0] = base[0];
	while (nbr > 0)
	{
		result[i] = base[nbr % base_len];
		nbr /= base_len;
		i--;
	}
	return (result);
}
