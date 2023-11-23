/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_diverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:55:18 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/23 13:14:53 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_pa_norm(int *tab, int tempo)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tempo = tab[i + 1];
		tab[i] = tempo;
		i++;
	}
	return (tab);
}

int	*ft_pa(int *tab_a, int *tab_b)
{
	int	tempo;
	int	second_tempo;
	int	i;
	int	size;

	i = 0;
	if (!tab_b)
		return (NULL);
	else
	{
		tempo = tab_b[0];
		tab_b = ft_pa_norm(tab_b, second_tempo);
		size = tab_size(tab_a);
		while (size > 0)
		{
			second_tempo = tab_a[size - 1];
			tab_a[size] = second_tempo;
			size--;
		}
		tab_a[0] = tempo;
		write(1, "pa\n", 3);
	}
	return (tab_a);
}

int	*ft_pb_norm(int *tab, int tempo)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tempo = tab[i + 1];
		tab[i] = tempo;
		i++;
	}
	return (tab);
}

int	*ft_pb(int *tab_a, int *tab_b)
{
	int	tempo;
	int	second_tempo;
	int	i;
	int	size;

	i = 0;
	if (!tab_a)
		return (NULL);
	else
	{
		tempo = tab_a[0];
		tab_a = ft_pb_norm(tab_a, second_tempo);
		size = tab_size(tab_b);
		while (size > 0)
		{
			second_tempo = tab_b[size - 1];
			tab_b[size] = second_tempo;
			size--;
		}
		tab_b[0] = tempo;
		write(1, "pb\n", 3);
	}
	return (tab_a);
}
