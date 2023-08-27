/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   solution.c                                        o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/27 02:53:00 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/27 20:23:18 by souaguen           oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
		while (i < map->size_x)
		{
			if (map->matrix[j][i] > tmp)
			{
				tmp = map->matrix[j][i];
				*pos_x = i;
				*pos_y = j;
			}
			i++;
		}
		i = 0;
		j++;
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

void	ft_find_solution(char *filename)
{
	t_map	*map;
	int		pos_x;
	int		pos_y;
	int		sq_size;
	int		i;

	map = extract_info_map(filename);
	split_tab_n_matrix(map);
	pos_x = 0;
	pos_y = 0;
	i = 0;
	sq_size = find_max(map, &pos_x, &pos_y);
	while ((i / sq_size) < sq_size)
	{
		map->tab[pos_y - (i / sq_size)][pos_x - (i % sq_size)] = map->full;
		i++;
	}
	ft_print_solution(map);
	free_map(map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->tab[i]);
		free(map->matrix[i]);
		i++;
	}
	free(map->tab);
	free(map->matrix);
	free(map);
}
