/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   extract_map.c                                     o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 17:46:40 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/28 00:47:03 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map	*extract_info_map(char *filename)
{
	char	*str;
	char	*f_line;
	t_map	*map;
	int		i;
	int		l;

	map = malloc(sizeof(t_map));
	str = read_map(filename);
	if (!len_file(filename))
		return (map);
	f_line = extract_first_line(str);
	i = next_newline(str);
	l = ft_strlen(f_line);
	l = l - 3;
	if (i < 0 || l < 0)
		return (map);
	map->size_y = ft_natoi(f_line, l);
	map->empty = *(f_line + l);
	map->obst = *(f_line + l + 1);
	map->full = *(f_line + l + 2);
	map->filename = filename;
	free(f_line);
	free(str);
	return (map);
}

int	get_min(t_map *map, int i, int j)
{
	int	tmp;
	int	left;
	int	upleft;
	int	up;

	up = map->matrix[j - 1][i];
	upleft = map->matrix[j - 1][i - 1];
	left = map->matrix[j][i - 1];
	tmp = left;
	if (up < tmp)
		tmp = up;
	if (upleft < tmp)
		tmp = upleft;
	return (tmp + 1);
}

void	allocate_tab_n_matrix(t_map *map)
{
	int	i;

	map->tab = (char **) malloc(sizeof(char *) * map->size_y);
	map->matrix = (int **) malloc(sizeof(int *) * map->size_y);
	i = 0;
	while (i < map->size_y)
	{
		map->tab[i] = malloc((sizeof(char) * map->size_x) + 1);
		map->matrix[i] = malloc(sizeof(int) * map->size_x);
		i++;
	}
}

void	fill_tab_n_matrix(t_map *map, int *i, int *j, int *k)
{
	char	*str_map;

	str_map = map->str_map;
	while (*j < map->size_y)
	{
		if (*(str_map + (*k)) == '\n')
		{
			map->tab[*j][*i] = '\0';
			*j = (int) *(j) + 1;
			*i = (int) 0;
		}
		else
		{
			map->tab[*j][*i] = *(str_map + (*k));
			if (map->tab[*j][*i] == map->obst)
				map->matrix[*j][*i] = 0;
			else if (*j == 0 || *i == 0)
				map->matrix[*j][*i] = 1;
			else
				map->matrix[*j][*i] = get_min(map, *i, *j);
			*(i) = (int) *(i) + 1;
		}
		*(k) = *(k) + 1;
	}
}

int	split_tab_n_matrix(t_map *map)
{
	char	*str_map;
	int		i;
	int		j;
	int		k;

	str_map = read_map(map->filename);
	k = next_newline(str_map) + 1;
	map->size_x = next_newline((str_map + k));
	map->str_map = str_map;
	j = 0;
	i = 0;
	allocate_tab_n_matrix(map);
	fill_tab_n_matrix(map, &i, &j, &k);
	free(str_map);
	return (1);
}
