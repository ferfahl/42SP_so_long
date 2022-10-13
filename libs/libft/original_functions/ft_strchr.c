/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:18:48 by feralves          #+#    #+#             */
/*   Updated: 2022/10/13 23:27:16 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief returns a pointer to the first occurrence of the character c in the
*string s
*@param s String to be scanned.
*@param c Character as integer to search.
*@return Pointer to the matched character or NULL if the character is not
 * found. The terminating null byte is considered part of the string, so that
 * if 'c' is specified as '\0', these functions return a pointer to the
 * terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if ((char)c == '\0')
		return (&str[ft_strlen(str)]);
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str++;
	}
	return (0);
}
