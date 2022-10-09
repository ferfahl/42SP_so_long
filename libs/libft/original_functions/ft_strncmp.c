/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:02:11 by feralves          #+#    #+#             */
/*   Updated: 2022/10/06 16:50:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief
*@param
*@return
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (((*s1 == *s2) && *s1 != '\0') && count < n - 1)
	{
		s1++;
		s2++;
		count++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
