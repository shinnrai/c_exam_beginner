/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 21:33:30 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/09 21:52:13 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int 	ft_atoi(char *str)
{
	int num = 0;
	while (*str == '\n' || *str == '\v' || *str == ' ' || *str == '\f' || *str == '\r' || *str == '\t')
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int		ft_isprime(int n)
{
	int i = 2;
	while (i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char c;
	if (n > 9)
		ft_putnbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int n;
	if (ac == 2 && (n = ft_atoi(av[1])) >= 0)
	{
		int i = 2;
		int sum = 0;
		while (i <= n)
		{
			if (ft_isprime(i) == 1)
				sum += i;
			i++;
		}
		ft_putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
