/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:54:32 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/18 11:34:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *ft_algo_2_arg(int *tab)
{
    int first;
    int second;

    first = tab[0];
    second = tab[1];
    if (first > second)
        tab = ft_sa(tab, 0);
    else
        return (tab);
}

int *ft_algo_3_arg(int *tab, int *tab_b)
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
        tab = ft_pb(tab, tab_b);
        tab = ft_sa(tab, 0);
        tab = ft_pa(tab, tab_b);
    }
    else
    {
        tab = ft_ra(tab, 4, 0);
        tab = ft_sa(tab, 0);
    }
    return(tab);
}

int *ft_algo_4_arg(int *tab, int *tab_b)
{
    int min;
    int max;
    int check;
    int i;

    i = 0;
    min = ft_min_in_tab(tab);
    max = ft_bigger_in_tab(tab);
    printf("max == %d & min == %d\n", max, min);
    if (min == 3)
        tab = ft_ra(tab, 5, 0);
    if (max == 2 && min == 0)
    {
        check = check_order(tab);
        while ((check - 1) != 0)
        {
            tab = ft_pb(tab, tab_b);
            i++;
            check --;
        }
        tab = ft_algo_3_arg(tab, tab_b);
        while (i != 0)
        {
            tab = ft_pa(tab, tab_b);
            i--;
        }
        return(tab);
    }
    else if (max >= 3)
    {
        return (ft_algo_3_arg(tab,tab_b));
    }
    else if (max == 0 )
    {
        printf("iciiiiii\n");
        tab = ft_ra(tab, 5, 0);
        return (ft_algo_3_arg(tab, tab_b));
    }
    else if (max == 2 ||max == 1)
    {
        printf("laaaaa\n");
        tab = ft_sa(tab, 0);
        return(ft_algo_4_arg(tab, tab_b));
    }
    return (tab);
}

int *ft_algo_5_arg(int *tab, int *tab_b)
{
    int min;
    int max;
    int i;

    i = 0;
    min = ft_min_in_tab(tab);
    max = ft_bigger_in_tab(tab);
    printf("algo 5 ==== max == %d & min == %d\n", max, min);
    if (max == 0)
    {
        tab = ft_ra(tab, 6, 0);
        return(ft_algo_4_arg(tab, tab_b));
    }
    if (max == 4)
        return(ft_algo_4_arg(tab, tab_b));
    return (tab);
}
