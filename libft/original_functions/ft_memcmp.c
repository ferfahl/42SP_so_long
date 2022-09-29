/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:54:46 by feralves          #+#    #+#             */
/*   Updated: 2022/06/17 02:45:39 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		count;
	const char	*first;
	const char	*second;

	first = (const char *)s1;
	second = (const char *)s2;
	count = 0;
	if (n == 0)
		return (0);
	while ((*first == *second) && count < n - 1)
	{
		first++;
		second++;
		count++;
	}
	return ((unsigned char)*first - (unsigned char)*second);
}
