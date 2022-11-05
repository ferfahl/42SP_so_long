/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:55 by feralves          #+#    #+#             */
/*   Updated: 2022/11/04 20:58:02 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Headers
# include "libs.h"
# include "define_bonus.h"

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
void	finding_p(t_count *c, char **dupe);

//opening
void	open_game(t_vars *vars);
void	start_window(t_data *fullmap);
void	load_img(t_vars *vars);
void	sprite_place(t_vars *vars, char **map);
void	load_xpm(t_vars *vars, t_draw *img, void *sprite);

//events
int		key_hook(int keycode, t_vars *vars);
int		click_hook(t_vars *vars);

//closing
void	destroy_and_free(t_vars *vars);
void	if_error(char *message, t_vars *vars);

#endif
