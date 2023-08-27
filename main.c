/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   main.c                                            o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/27 19:17:41 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/28 00:45:19 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "lib/header.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (!len_file(argv[1]))
	{
		write(2, "map error\n", 10);
		return (2);
	}
	ft_find_solution(argv[1]);
	return (0);
}
