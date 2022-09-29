/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:01:35 by feralves          #+#    #+#             */
/*   Updated: 2022/07/14 17:21:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
