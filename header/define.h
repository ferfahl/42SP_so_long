/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:02:51 by feralves          #+#    #+#             */
/*   Updated: 2022/10/30 12:04:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//Headers
# include "so_long.h"
# include "libs.h"

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

typedef struct s_imagem
{
	void	*img;
	char	*addr; //address
	int		bpp; //bits per pixel
	int		line_size;
	int		endian; //relação à transparencia
}				t_imagem;

typedef struct s_imgs
{
	t_imagem	cavalinho;
	t_imagem	wall;
	t_imagem	item;
	t_imagem	endpoint;
	t_imagem	floor;
	t_imagem	temp1;
}				t_imgs;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img_static;
	int		steps;
	t_data	*fullmap;
	t_imgs	sprite;
}				t_vars;

//Definitions paths
# define SPRITE_WALL "./assets/sprites/wall.xpm"
# define SPRITE_CHAR "./assets/sprites/char.xpm"
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
