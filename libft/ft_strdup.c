/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:53:59 by rparodi           #+#    #+#             */
/*   Updated: 2023/11/16 15:12:05 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*to_return;

	len = ft_strlen(s) + 1;
	to_return = (char *)malloc(sizeof(char) * len);
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, s, len);
	return (to_return);
}
