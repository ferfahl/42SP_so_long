/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:04:48 by feralves          #+#    #+#             */
/*   Updated: 2022/07/14 18:42:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	bigcount;
	size_t	littlecount;

	bigcount = 0;
	littlecount = 0;
	index = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[index] != '\0' && index <= len - ft_strlen(little))
	{
		while (big[bigcount++] == little[littlecount++])
		{
			if (little[littlecount] == '\0')
				return ((char *)&big[index]);
		}
		littlecount = 0;
		index++;
		bigcount = index;
	}
	return (0);
}
