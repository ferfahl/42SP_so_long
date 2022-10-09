/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:59:31 by feralves          #+#    #+#             */
/*   Updated: 2022/10/06 16:50:20 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief
*@param
*@return
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	index;
	size_t			max_size;

	index = 0;
	max_size = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	max_size = ft_strlen(s) - start;
	if (max_size > len)
		max_size = len;
	substring = malloc((max_size + 1) * sizeof(*substring));
	if (!substring)
		return (NULL);
	while (index < max_size)
	{
		substring[index] = s[start];
		start++;
		index++;
	}
	substring[index] = '\0';
	return (substring);
}
