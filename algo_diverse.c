/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_diverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:55:18 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/28 12:37:05 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_pa_norm(int *tab, int tempo, int size)
{
	int	i;

	i = 0;
	tempo = 0;
	while (size > 0)
	{
		tempo = tab[i + 1];
		tab[i] = tempo;
		i++;
		size--;
	}
	return (tab);
}

int	*ft_pa(int *tab_a, int *tab_b, int size)
{
	int	tempo;
	int	second_tempo;
	int	i;

	i = 0;
	second_tempo = 0;
	if (!tab_b)
		return (NULL);
	else
	{
		tempo = tab_b[0];
		tab_b = ft_pa_norm(tab_b, second_tempo, size);
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

int	*ft_pb_norm(int *tab, int tempo, int size)
{
	int	i;
	int size_tempo;

	size_tempo = size;
	i = 0;
	tempo = 0;
	while (size > 0)
	{
		tempo = tab[i + 1];
		tab[i] = tempo;
		i++;
		size --;
	}
	tab[size_tempo] = 0;
	return (tab);
}

int	*ft_pb(int *tab_a, int *tab_b, int size)
{
	int	tempo;
	int	second_tempo;
	int	i;

	i = 0;
	second_tempo = 0;
	if (!tab_a)
		return (NULL);
	else
	{
		printf("|avant|%d:%d:%d:%d:%d:%d|||\n", tab_a[0], tab_a[1], tab_a[2], tab_a[3], tab_a[4], tab_a[5]);
		tempo = tab_a[0];
		tab_a = ft_pb_norm(tab_a, second_tempo, size);
		while (size > 0)
		{
			second_tempo = tab_b[size - 1];
			tab_b[size] = second_tempo;
			size--;
		}
		// printf("|a|%d:%d:%d:%d:%d:%d|||\n", tab_a[0], tab_a[1], tab_a[2], tab_a[3], tab_a[4], tab_a[5]);
		// printf("%d\n", tab_a[4]);
		// printf("|b|%d:%d:%d:%d:%d:%d|||\n", tab_b[0], tab_b[1], tab_b[2], tab_b[3], tab_b[4], tab_b[5]);
		// printf("avaaant%d\n", tab_a[4]);
		printf("%p %p\n", &tab_b[0], &tab_a[4]);
		tab_b[0] = tempo;
		// printf("apressssss%d\n", tab_a[4]);
		// //tab_a[5] = 18599;
		// printf("|A|%d:%d:%d:%d:%d:%d|||\n", tab_a[0], tab_a[1], tab_a[2], tab_a[3], tab_a[4], tab_a[5]);
		// printf("%d\n", tab_a[4]);
		// printf("|B|%d:%d:%d:%d:%d:%d|||\n", tab_b[0], tab_b[1], tab_b[2], tab_b[3], tab_b[4], tab_b[5]);
		write(1, "pb\n", 3);
	}
	return (tab_a);
}
