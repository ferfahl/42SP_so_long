/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:27:33 by feralves          #+#    #+#             */
/*   Updated: 2022/10/06 16:49:41 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief
*@param
*@return
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	uns_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		uns_n = (unsigned int)(n * (-1));
	}
	else
		uns_n = (unsigned int)n;
	if (uns_n >= 10)
		ft_putnbr_fd((uns_n / 10), fd);
	ft_putchar_fd((uns_n % 10) + '0', fd);
}
