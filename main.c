/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   main.c                                            o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/27 02:53:00 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/27 03:27:13 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */
#include "lib/header.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	
	if (argc < 2)
		return (1);
	map = extract_info_map(argv[1]);
	printf("nb_lines: %d\nEmpty: %c\nObstacle: %c\nFull: %c\n", map->size_y, map->empty, map->obst, map->full);
	free(map);	
	return (0);
}
