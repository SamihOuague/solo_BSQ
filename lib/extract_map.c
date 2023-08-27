/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   extract_map.c                                     o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 17:46:40 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/27 15:39:34 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int     ft_strlen(char *str)
{
	int     i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}


int	ft_natoi(char *str, int n)
{
	int	nbr;
	int	i;
	int	p;

	nbr = 0;
	i = 0;
	p = 1;
	if (*(str + i) == '-')
	{
		p *= -1;
		i++;
	}
	else if (*(str + i) == '+')
		i++;
	while (*(str + i) != '\0' && i < n)
	{
		if (!(*(str + i) >= '0' && *(str + i) <= '9'))
			return (n * p);
		nbr = (nbr * 10) + (*(str + i) - '0');
		i++;
	}
	return (nbr * p);
}

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

int	get_min(int left, int up, int upleft)
{
	int	tmp;

	tmp = left;
	if (up < tmp)
		tmp = up;
	if (upleft < tmp)
		tmp = upleft;
	return (tmp + 1);
}

int     split_tab_n_matrix(t_map *map)
{
        char    *str_map;
        int             i;
        int             j;
        int             k;
	int		tmp;

        map->tab = malloc(sizeof(char *) * map->size_y);
        map->matrix = malloc(sizeof(int *) * map->size_y);
        str_map = read_map(map->filename);
        k = next_newline(str_map) + 1;
        map->size_x = next_newline((str_map + k));
        j = 0;
        i = 0;
	tmp = 0;
        map->tab[j] = malloc((sizeof(char) * map->size_x) + 1);
        map->matrix[j] = malloc(sizeof(int) * map->size_x);
        while (*(str_map + k) != '\0')
        {
                if (*(str_map + k) == '\n')
                {
                        map->tab[j][i] = '\0';
                        i = 0;
                        j++;
                        map->tab[j] = malloc((sizeof(char) * map->size_x) + 1);
                        map->matrix[j] = malloc(sizeof(int) * map->size_x);
                }
                else
                {
                        map->tab[j][i] = *(str_map + k);
			if (*(str_map + k) == map->obst)
				tmp = 0;
			else if (i == 0 || j == 0)
				tmp = 1;
			else
				tmp = get_min(map->matrix[j - 1][i - 1],
                                                        map->matrix[j][i - 1],
                                                        map->matrix[j - 1][i]);
			map->matrix[j][i] = tmp;
                        i++;
                }
                k++;
        }
        return (1);
}
