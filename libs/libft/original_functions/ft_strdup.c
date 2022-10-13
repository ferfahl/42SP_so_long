/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:01:35 by feralves          #+#    #+#             */
/*   Updated: 2022/10/13 23:26:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief returns a pointer to a new string which is a duplicate of the string s
*Memory for the new string is obtained with malloc, and can be freed with free
*@param s String to be duplicated
*@return Pointer to the duplicated string, or NULL if insufficient memory was
*available
*/

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		count;

	count = 0;
	duplicate = malloc(ft_strlen(s) * sizeof(*duplicate) + 1);
	if (!duplicate)
		return (NULL);
	while (*s)
		duplicate[count++] = *s++;
	duplicate[count] = '\0';
	return (duplicate);
}
