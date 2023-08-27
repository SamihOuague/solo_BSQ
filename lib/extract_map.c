/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   extract_map.c                                     o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 17:46:40 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/27 03:16:20 by anonymous          oo         oo         */
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
	free(f_line);
	free(str);
	return (map);
}
