/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:26:12 by feralves          #+#    #+#             */
/*   Updated: 2022/09/20 22:35:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx-linux/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void)win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}
