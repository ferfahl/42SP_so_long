/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:55:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/06 16:50:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief
*@param
*@return
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	result;

	count = 0;
	result = ft_strlen(dst) + ft_strlen(src);
	if (size < ft_strlen(dst))
		result = (size + ft_strlen(src));
	while (dst[count] && size != 0)
	{
		count++;
		size--;
	}
	if (size > 0)
		ft_strlcpy(&dst[count], src, size);
	return (result);
}
