/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   header.h                                          o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 18:58:21 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/28 00:39:50 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct t_map {
	char	**tab;
	char	*filename;
	char	*str_map;
	char	empty;
	char	obst;
	char	full;
	int		**matrix;
	int		size_x;
	int		size_y;
}	t_map;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_print_solution(t_map *map);
void	ft_find_solution(char *filename);
void	free_map(t_map *map);
char	*read_map(char *filename);
char	*extract_first_line(char *s);
t_map	*extract_info_map(char *filename);
int		next_newline(char *s);
int		len_file(char *filename);
int		ft_strlen(char *str);
int		ft_natoi(char *str, int n);
int		split_tab_n_matrix(t_map *map);
int		find_max(t_map *map, int *pos_x, int *pos_y);
