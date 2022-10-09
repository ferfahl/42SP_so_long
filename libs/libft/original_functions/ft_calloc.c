/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:35:00 by feralves          #+#    #+#             */
/*   Updated: 2022/10/06 16:48:39 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief
*@param
*@return
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		total;
	char	*str;

	total = nmemb * size;
	if (size != 0 && total / size != nmemb)
		return (NULL);
	str = malloc(total * sizeof(*str));
	if (!str)
		return (NULL);
	ft_bzero(str, total);
	return (str);
}
