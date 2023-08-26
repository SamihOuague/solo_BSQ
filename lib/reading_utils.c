/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   reading_utils.c                                   o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 19:07:42 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/26 19:42:31 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int     len_file(char *filename)
{
        char    tmp;
        int             file;
        int             i;

        file = open(filename, O_RDONLY);
        if (file == -1)
                return (0);
        i = 0;
        while (read(file, &tmp, 1))
                i++;
        close(file);
        return (i);
}

char    *read_map(char *filename)
{
        char    tmp;
        char    *str;
        int             len;
        int             file;
        int             i;

        str = NULL;
        len = len_file(filename);
        if (len == -1)
                return (str);
        str = malloc((sizeof(char) * len) + 1);
        file = open(filename, O_RDONLY);
        i = 0;
        while (read(file, &tmp, 1))
        {

                *(str + i) = tmp;
                i++;
        }
        *(str + i) = '\0';
        close(file);
        return (str);
}

char	*extract_first_line(char *s)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = next_newline(s);
	str = malloc((sizeof(char) * l) + 1);
	while (*(s + i) != '\n')
	{
		*(str + i) = *(s + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

int	next_newline(char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\n' && *(s + i) != '\0')
		i++;
	return (i);
}
