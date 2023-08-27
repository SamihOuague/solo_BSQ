/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   output_utils.c                                    o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/26 19:04:03 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/28 00:37:17 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	n;
	int				mod;

	n = nb;
	if (nb < 0)
		n = -nb;
	mod = n % 10;
	if (n > 10)
		ft_putnbr(n / 10);
	ft_putchar(mod + '0');
}

int	ft_strlen(char *str)
{
	int	i;

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
