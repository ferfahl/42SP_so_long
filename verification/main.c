/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:33:41 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 20:50:08 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int argc, char **argv)
{
	t_data	fullmap;

	if (check_error_1(argc, argv, &fullmap))
		return (1);
	fullmap.map = malloc((fullmap.height + 1) * sizeof(char *));
	write_map(argv[1], &fullmap);
	if (check_error_2(&fullmap))
		return (1);
	check_path(&fullmap);
}
