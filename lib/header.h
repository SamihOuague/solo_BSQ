/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   header.h                                          o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 18:58:21 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/26 20:11:16 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct o_map {
        char    **tab;
        char    empty;
        char    obst;
        char    full;
        int             **matrix;
        int             size_x;
        int             size_y;
} o_map;

void    ft_putchar(char c);
void    ft_putstr(char *str);
char    *read_map(char *filename);
char    *extract_first_line(char *s);
int		next_newline(char *s);
int             len_file(char *filename);
int		ft_strlen(char *str);
