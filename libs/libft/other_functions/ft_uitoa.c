/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:19:50 by feralves          #+#    #+#             */
/*   Updated: 2022/08/19 22:53:08 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(unsigned int number);
static void	ft_write(int size, char *string, unsigned int n);

char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*string;

	size = 0;
	size = (ft_counter(n));
	string = malloc(size + 1);
	if (!string)
		return (NULL);
	string[size] = '\0';
	size--;
	ft_write(size, string, n);
	return (string);
}

static int	ft_counter(unsigned int number)
{
	int	count;

	count = 1;
	while (number > 9)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

static void	ft_write(int size, char *string, unsigned int n)
{
	while (size >= 0)
	{
		string[size] = '0' + (n % 10);
		n = n / 10;
		size--;
	}
}
