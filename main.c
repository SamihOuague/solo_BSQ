/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   main.c                                            o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/27 02:53:00 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/27 16:30:51 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */
#include "lib/header.h"

int	find_max(t_map *map, int *pos_x, int *pos_y)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (j < map->size_y)
	{
		if (i == map->size_x)
		{
			i = 0;
			j++;
		}
		else
		{
			if (map->matrix[j][i] > tmp)
			{
				tmp = map->matrix[j][i];
				*pos_x = i;
				*pos_y = j;
			}
			i++;
		}
	}
	return (tmp);
}

void	ft_print_solution(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size_y)
	{
		ft_putstr(map->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int	pos_x;
	int	pos_y;
	int	square_size;
	int	i;

	if (argc < 2)
		return (1);
	map = extract_info_map(argv[1]);
	split_tab_n_matrix(map);
	pos_x = 0;
	pos_y = 0;
	i = 0;
	square_size = find_max(map, &pos_x, &pos_y);
	while ((i / square_size) < square_size)
	{
		map->tab[pos_y - (i / square_size)][pos_x - (i % square_size)] = map->full;
		i++;
	}
	ft_print_solution(map);

	free(map);
	return (0);
}
