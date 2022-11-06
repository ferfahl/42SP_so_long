/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:33:41 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 13:55:28 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	if_check_error(t_data fullmap)
{
	ft_free_array(fullmap.map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	fullmap;

	if (check_error_1(argc, argv, &fullmap))
		return (1);
	fullmap.map = malloc((fullmap.height + 1) * sizeof(char *));
	write_map(argv[1], &fullmap);
	if (check_error_2(&fullmap))
		return (if_check_error(fullmap));
	if (check_path(&fullmap))
		return (if_check_error(fullmap));
	start_window(&fullmap);
}
