/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:05:03 by feralves          #+#    #+#             */
/*   Updated: 2022/10/06 16:50:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief
*@param
*@return
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	dest = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	while (s2[index] != '\0')
	{
		dest[count + index] = s2[index];
		index++;
	}
	dest[count + index] = '\0';
	return (dest);
}
