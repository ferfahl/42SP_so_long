/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:02:51 by feralves          #+#    #+#             */
/*   Updated: 2022/11/05 12:34:02 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_BONUS_H
# define DEFINE_BONUS_H

//Headers
# include "so_long_bonus.h"
# include "libs_bonus.h"

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
	int	villain;
	int	index;
}				t_count;

typedef struct s_draw
{
	void	*img;
}				t_draw;

typedef struct s_imgs
{
	t_draw	right_p;
	t_draw	left_p;
	t_draw	wall;
	t_draw	item;
	t_draw	endpoint;
	t_draw	floor;
	t_draw	villain;
	t_draw	temp1;
}				t_imgs;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img_static;
	int		steps;
	t_data	*fullmap;
	t_imgs	sprite;
	int		is_right;
}				t_vars;

//Definitions paths
# define SPRITE_CHAR_RIGHT "./assets/sprites/char.xpm"
# define SPRITE_CHAR_LEFT "./assets/sprites/char_left.xpm"
# define SPRITE_VILLAIN "./assets/sprites/villain.xpm"
# define SPRITE_WALL "./assets/sprites/wall.xpm"
# define SPRITE_ITEM "./assets/sprites/collectible.xpm"
# define SPRITE_EXIT "./assets/sprites/exit.xpm"
# define SPRITE_FLOOR "./assets/sprites/floor.xpm"
# define SPRITE_TEMP1 "./assets/sprites/temp1.xpm"
# define MAP_ARCH "./assets/maps/test.ber"

//Definitions
# define PIXEL_SIZE 32
# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define VILLAIN 'V'
# define COLLECTIBLE 'C'
# define ENDPOINT 'E'
# define FLOOD 'F'
# define TEMP1 'K'

//Error definitions
# define ERROR_MAP_1 "Invalid path"
# define ERROR_MAP_2 "Empty map"
# define ERROR_MAP_3 "Wrong map format"
# define ERROR_MAP_4 "Where are the walls?"
# define ERROR_MAP_5 "Invalid characters"
# define ERROR_MAP_6 "Wrong number of characters/collectibles"
# define ERROR_MAP_7 //valid dimension [tamanho máximo?]
# define ERROR_ARG_1 "Invalid number of arguments"
# define ERROR_ARG_2 "Invalid extension"
# define ERROR_ARG_3 "File not found"

#endif
