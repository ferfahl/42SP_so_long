/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:55 by feralves          #+#    #+#             */
/*   Updated: 2022/10/15 12:17:38 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Libraries
# include <stdlib.h>
# include <X11/keysym.h>

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"

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

//Functions

//opening
void	load_sprite(t_vars *vars, void *sprite);
void	open_game(t_vars *vars);

//closing
int		esc_hook(int keycode, t_vars *vars);
int		click_hook(t_vars *vars);
void	destroy_and_free(t_vars *vars);


//Definitions paths
# define SPRITE_WALL "./assets/sprites/wall.xpm"
# define SPRITE_CHAR "./assets/sprites/char.xpm"

//Definitions
# define PIXEL_SIZE 64

#endif