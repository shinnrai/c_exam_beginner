/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 22:28:34 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/09 22:47:53 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char array[2048];
unsigned char *p = array;

void	interpret(char *input)
{
	int i = 0;
	int loop;
	while (input[i])
	{
		char c = input[i];
		if 		(c == '>') ++p;
		else if (c == '<') --p;
		else if (c == '+') ++(*p);
		else if (c == '-') --(*p);
		else if (c == '.') write(1, p, 1);
		else if (c == '[' && *p == 0)
		{
			loop = 1;
			while (loop > 0)
			{
				c = input[++i];
				if (c == '[')
					loop++;
				else if (c == ']')
					loop--;
			}
		}
		else if (c == ']' && *p != 0)
		{
			loop = 1;
			while (loop > 0)
			{
				c = input[--i];
				if (c == '[')
					loop--;
				else if (c == ']')
					loop++;
			}
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = -1;
		while (++i < 2048)
			array[i] = 0;
		interpret(av[1]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
