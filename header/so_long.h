/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:55 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 10:31:41 by feralves         ###   ########.fr       */
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

typedef struct s_data
{
	char	**map;
	size_t	height;
	size_t	width;
}				t_data;


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
# define MAP_ARCH "./assets/maps/map1.ber"

//Definitions
# define PIXEL_SIZE 64

//Error definitions
# define ERROR_MAP_1 "File.ber not found" //se encontrou um arquivo e se o arquivo é .ber
# define ERROR_MAP_2 "Empty map"
# define ERROR_MAP_3 "Wrong map format" //não retangular
# define ERROR_MAP_4 "Where are the walls?" //paredes erradas
# define ERROR_MAP_5 "Invalid characters"
# define ERROR_MAP_6 "Wrong number of characters/collectibles" //no collectible
# define ERROR_MAP_7 //"valid path"
# define ERROR_MAP_8 //valid dimension [tamanho máximo?]

#endif