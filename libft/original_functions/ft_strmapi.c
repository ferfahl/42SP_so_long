/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:21 by feralves          #+#    #+#             */
/*   Updated: 2022/07/14 18:41:24 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*dest;

	count = 0;
	if (!s || !f)
		return (NULL);
	dest = malloc((ft_strlen(s) + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	while (s[count] != '\0')
	{
		dest[count] = f(count, s[count]);
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
