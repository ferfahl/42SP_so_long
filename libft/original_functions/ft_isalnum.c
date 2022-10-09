/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:08:46 by feralves          #+#    #+#             */
/*   Updated: 2022/10/06 16:48:42 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief
*@param
*@return
*/

int	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (2);
	else if (ft_isalpha(c))
		return (1);
	return (0);
}
