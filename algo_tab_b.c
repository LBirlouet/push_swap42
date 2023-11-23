/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tab_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:32:47 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/23 13:15:17 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sb(int *tab_b, int y)
{
	int	tempo;

	tempo = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = tempo;
	if (y != 1)
		write(1, "sb\n", 3);
	return (tab_b);
}

int	*ft_rb(int *tab_b, int argc, int y)
{
	int	tempo;
	int	first;
	int	i;

	i = 1;
	first = tab_b[0];
	while (i < (argc - 1))
	{
		tempo = tab_b[i];
		tab_b[i - 1] = tempo;
		i++;
	}
	tab_b[argc - 2] = first;
	if (y != 1)
		write(1, "rb\n", 3);
	return (tab_b);
}

int	*ft_rrb(int *tab_b, int argc, int y)
{
	int	tempo;
	int	last;
	int	i;

	i = argc - 2;
	last = tab_b[argc - 2];
	while (i > 0)
	{
		tempo = tab_b[i - 1];
		tab_b[i] = tempo;
		i--;
	}
	tab_b[0] = last;
	if (y != 1)
		write(1, "rrb\n", 4);
	return (tab_b);
}
