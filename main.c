/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   main.c                                            o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 17:46:40 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/26 20:45:42 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "lib/header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	extract_info_map(char *filename)
{
	int	i;
	int	l;
	char    *str;
        char    *f_line;

        str = read_map(filename);
        f_line = extract_first_line(str);
	i = next_newline(str);
	l = ft_strlen(f_line);

	l = l - 3;

	if (i < 0 || l < 0)
		return (0);
	
	if (*(str + i) == '\n')
		i++;
	
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}


	free(f_line);
        free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	
	
	if (argc != 2)
		return (1);
	extract_info_map(argv[1]);
	return (0);
}
