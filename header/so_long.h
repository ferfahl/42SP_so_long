/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:55 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 21:29:26 by feralves         ###   ########.fr       */
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

//Structs
typedef struct s_data
{
	char	**map;
	int		height;
	int		width;
	int		collectibles;
}				t_data;

typedef struct s_count
{
	int	row;
	int	collumn;
	int	player;
	int	endpoint;
	int	index;
}				t_count;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	t_data	*fullmap;
}				t_vars;

//Functions
//check
int		map_height(char *file);
int		map_width(t_data *fullmap);
void	write_map(char *file, t_data *fullmap);
int		check_ber(char *str);
int		check_error_1(int argc, char **argv, t_data *fullmap);
int		check_error_2(t_data *fullmap);
int		check_walls(t_data *fullmap);
int		check_extras(t_data *fullmap);
int		check_path(t_data *fullmap);

//opening
void	load_sprite(t_vars *vars, void *sprite, int x, int y);
void	open_game(t_vars *vars);
void	start_window(t_data *fullmap);

//closing
int		esc_hook(int keycode, t_vars *vars);
int		click_hook(t_vars *vars);
void	destroy_and_free(t_vars *vars);

//Definitions paths
# define SPRITE_WALL "./assets/sprites/wall.xpm"
# define SPRITE_CHAR "./assets/sprites/char.xpm"
# define MAP_ARCH "./assets/maps/test.ber"

//Definitions
# define PIXEL_SIZE 64
# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define ENDPOINT 'E'
# define FLOOD 'F'

//Error definitions
# define ERROR_MAP_1 "Invalid path"
# define ERROR_MAP_2 "Empty map"
# define ERROR_MAP_3 "Wrong map format" //não retangular
# define ERROR_MAP_4 "Where are the walls?" //paredes erradas
# define ERROR_MAP_5 "Invalid characters"
# define ERROR_MAP_6 "Wrong number of characters/collectibles" //no collectible
# define ERROR_MAP_7 //valid dimension [tamanho máximo?]
# define ERROR_ARG_1 "Invalid number of arguments"
# define ERROR_ARG_2 "Invalid extension"
# define ERROR_ARG_3 "File not found"

#endif