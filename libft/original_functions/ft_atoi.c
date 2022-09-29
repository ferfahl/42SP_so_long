/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:05:28 by feralves          #+#    #+#             */
/*   Updated: 2022/06/28 03:35:47 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	count;
	int	result;
	int	signal;

	signal = 1;
	count = 0;
	result = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			signal = -1;
		count++;
	}
	while (count < (int)ft_strlen(nptr) && ft_isdigit(nptr[count]))
	{
		result = result * 10 + (nptr[count] - 48);
		count++;
	}
	return (result * signal);
}
