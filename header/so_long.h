/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:55 by feralves          #+#    #+#             */
/*   Updated: 2022/10/24 15:06:13 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Headers
# include "libs.h"
# include "define.h"

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
//void	load_sprite(t_vars *vars, void *sprite, int x, int y);
void	open_game(t_vars *vars);
void	start_window(t_data *fullmap);

//closing
int		esc_hook(int keycode, t_vars *vars);
int		click_hook(t_vars *vars);
void	destroy_and_free(t_vars *vars);

#endif
