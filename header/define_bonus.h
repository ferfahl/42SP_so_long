/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:02:51 by feralves          #+#    #+#             */
/*   Updated: 2022/11/05 19:45:55 by feralves         ###   ########.fr       */
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

typedef struct	s_frame_p
{
	t_draw	right1;
	t_draw	right2;
	t_draw	left1;
	t_draw	left2;
	
}				t_frame_p;

typedef struct s_frames
{
	t_draw	op1;
	t_draw	op2;
}				t_frames;

typedef struct s_imgs
{
	t_frame_p	player;
	t_frame_p	villain;
	t_frames	wall;
	t_frames	item;
	t_frames	floor;
	t_draw		endpoint;
	t_draw		temp1;
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
# define SPRITE_CHAR_R1 "./assets/sprites_bonus/char_right1.xpm"
# define SPRITE_CHAR_R2 "./assets/sprites_bonus/char_right2.xpm"
# define SPRITE_CHAR_L1 "./assets/sprites_bonus/char_left1.xpm"
# define SPRITE_CHAR_L2 "./assets/sprites_bonus/char_left2.xpm"
# define SPRITE_V1 "./assets/sprites_bonus/villain_1.xpm"
# define SPRITE_V2 "./assets/sprites_bonus/villain_2.xpm"
# define SPRITE_V3 "./assets/sprites_bonus/villain_3.xpm"
# define SPRITE_W1 "./assets/sprites_bonus/wall_1.xpm"
# define SPRITE_W2 "./assets/sprites_bonus/wall_2.xpm"
# define SPRITE_I1 "./assets/sprites_bonus/collectible_1.xpm"
# define SPRITE_I2 "./assets/sprites_bonus/collectible_2.xpm"
# define SPRITE_F1 "./assets/sprites_bonus/empty_1.xpm"
# define SPRITE_F2 "./assets/sprites_bonus/empty_2.xpm"
# define SPRITE_T1 "./assets/sprites_bonus/temp1.xpm"
# define SPRITE_T2 "./assets/sprites_bonus/temp2.xpm"
# define SPRITE_EXIT "./assets/sprites_bonus/exit.xpm"
# define MAP_ARCH "./assets/maps/map_square_bonus.ber"


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
# define ERROR_MAP_7 "Map too big"
# define ERROR_ARG_1 "Invalid number of arguments"
# define ERROR_ARG_2 "Invalid extension"
# define ERROR_ARG_3 "File not found"

#endif
