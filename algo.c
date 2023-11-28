/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:54:32 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/28 12:39:41 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_algo_2_arg(int *tab)
{
	int	first;
	int	second;

	first = tab[0];
	second = tab[1];
	if (first > second)
		tab = ft_sa(tab, 0);
	return (tab);
}

int	*ft_algo_3_arg(int *tab, int *tab_b)
{
	if (tab[0] < tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		return (tab);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		tab = ft_ra(tab, 4, 0);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		tab = ft_sa(tab, 0);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
		tab = ft_rra(tab, 4, 0);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		tab = ft_pb(tab, tab_b, 3);
		tab = ft_sa(tab, 0);
		tab = ft_pa(tab, tab_b, 3);
	}
	else
	{
		tab = ft_ra(tab, 4, 0);
		tab = ft_sa(tab, 0);
	}
	return (tab);
}

int	*ft_algo_4_arg(int *tab, int *tab_b)
{
	int	min;
	int	max;
	int	check;
	int	i;

	i = 0;
	min = ft_min_in_tab(tab, 4);
	max = ft_bigger_in_tab(tab, 4);
	check = check_order(tab, 4);
	if (check == 0)
		return (tab);
	max = ft_bigger_in_tab(tab, 4);
	if (min == 3)
	{
		tab = ft_rra(tab, 5, 0);
		min = 0;
	}
	if (min == 0 && (check_order(tab, 4) != 0))
	{
	printf("%p %p\n", &tab_b[0], &tab[4]);
		tab = ft_pb(tab, tab_b, 4);
		printf("oui|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		printf("|%d:%d:%d:%d:%d:%d|\n", tab_b[0], tab_b[1], tab_b[2], tab_b[3], tab_b[4], tab_b[5]);
		tab = ft_algo_3_arg(tab, tab_b);
		return (ft_pa(tab, tab_b, 4));
	}
	if (max == 0)
	{
	printf("%p %p\n", &tab_b[0], &tab[4]);
		tab = ft_ra(tab, 5, 0);
		printf("rrrra|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		return (ft_algo_4_arg(tab, tab_b));
	}
	if (min == 1)
	{
		tab = ft_sa(tab, 0);
//		printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		tab = ft_algo_4_arg(tab, tab_b);
	}
	if (min == 4)
		tab = ft_rra(tab, 5, 0);
	while (min > 1)
	{
		tab = ft_ra(tab, 5, 0);
//		printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		min--;
	}
	if (min == 0 && (check_order(tab, 4) != 0))
	{
		tab = ft_pb(tab, tab_b, 4);
		//printf("PPPPPP|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		tab = ft_algo_3_arg(tab, tab_b);
//		printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		return (ft_pa(tab, tab_b, 4));
	}
	if (check_order(tab, 4) != 0)
		return (ft_algo_4_arg(tab, tab_b));
	return (tab);
}

int	*ft_algo_5_arg(int *tab, int *tab_b)
{
	int	min;
	int	max;
	int	check;
	int	i;

	i = 0;
	max = ft_bigger_in_tab(tab, 5);
	check = check_order(tab, 5);
	if (check == 0)
		return (tab);
	if (max == 0)
	{
		tab = ft_ra(tab, 6, 0);
		printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	}
	if (max == 1)
	{
		tab = ft_sa(tab, 0);
//		printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		return (ft_algo_5_arg(tab, tab_b));
	}
	min = ft_min_in_tab(tab, 5);
	if (min == 1)
		tab = ft_sa(tab, 0);
	min = ft_min_in_tab(tab, 5);
	if (min == 0 && (check_order(tab, 5) != 0))
	{
		tab = ft_pb(tab, tab_b, 5);
//		printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		tab = ft_algo_4_arg(tab, tab_b);
		tab = ft_pa(tab, tab_b, 5);
		return (tab);
	}
	while (min > 1)
	{
		if (min > 2)
		{
			tab = ft_rra(tab, 6, 0);
		}
		else
		{
			tab = ft_ra(tab, 6, 0);
//			printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
		}
		min = ft_min_in_tab(tab, 5);
	}
//	printf("||%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	return (ft_algo_5_arg(tab, tab_b));
}

int	*big_algo(int *tab, int *tab_b, int size)
{
	int	min;
	int	check;
	int	i;
	int	size_down;
	
	printf("TSSS\n\n");
	min = ft_min_in_tab(tab, size);
	check = check_order(tab, size);
	size_down = size;
	// printf("|%d:%d:%d:%d:%d:%d|\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	// printf("|%d:%d:%d:%d:%d:%d|\n", tab_b[0], tab_b[1], tab_b[2], tab_b[3], tab_b[4], tab_b[5]);
	//
	int	z;
	z = 0;
	while (z < 10)
	{
		printf("tab[%d]=|%d|", z, tab[z]);
		z++;
	}
	//tesssssttttttttt
	//
	//
	
	i = 0;
	if (check == 0)
		return (tab);
	if (size <= 5)
		return (ft_algo_5_arg(tab, tab_b));
	if (min > 0)
	{
		min = ft_min_in_tab(tab, size);
		if (min > (size / 2))
			tab = ft_rra(tab, size + 1, 0);
		else
			tab = ft_ra(tab, size + 1, 0);
	}
	if (min == 0 && size > 5)
	{
		min = ft_min_in_tab(tab, size);
		tab = ft_pb(tab, tab_b, size);
		size --;
		tab = big_algo(tab, tab_b, size);
		//printf("oui\n");
		tab = ft_pa(tab, tab_b, size);
	}
	return (big_algo(tab, tab_b, size));
}
