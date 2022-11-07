/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:15:24 by feralves          #+#    #+#             */
/*   Updated: 2022/10/10 18:26:10 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief outputs the character ’c’ to the given file descriptor
*@param c: The character to output.
*@param fd: The file descriptor on which to write.
*@return none
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
