/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:55 by feralves          #+#    #+#             */
/*   Updated: 2022/10/09 15:26:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//struct
typedef struct s_test
{
	char    *temp;
	char    *aux;
	int     index;
}				t_test;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

//Libraries
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"

//Functions

#endif