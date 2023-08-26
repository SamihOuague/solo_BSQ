/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   output_utils.c                                    o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                #######            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 19:04:03 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/26 19:16:00 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while (*(str + i) != '\0')
        {
                ft_putchar(*(str + i));
                i++;
        }

}

void    ft_putnbr(int nb)
{
        unsigned int    n;
        int             mod;

        n = nb;
        if (nb < 0)
                n = -nb;
        mod = n % 10;
        if (n > 10)
                ft_putnbr(n / 10);
        ft_putchar(mod + '0');
}
