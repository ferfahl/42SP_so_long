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
#include "./libs/libft/libft.h"
#include <stdlib.h>
#include <X11/keysym.h>
/* 
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void)win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x000000);
	mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
} */

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

int	esc_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	ft_printf("%d\n", keycode);
	return (0);
}

int click_hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return(0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "42SP");
	mlx_hook(vars.win, 2, 1L<<0, esc_hook, &vars);
	mlx_hook(vars.win, 17, 1L<<2, click_hook, &vars);
	mlx_loop(vars.mlx);
}