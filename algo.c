/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:54:32 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/23 10:28:55 by lbirloue         ###   ########.fr       */
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
    min = ft_min_in_tab(tab, 4);
    max = ft_bigger_in_tab(tab, 4);
    check = check_order(tab);
    if (check == 0)
        return (tab);
    max = ft_bigger_in_tab(tab, 4);
    if (min == 3)
    {
        tab = ft_rra(tab, 5, 0);
        min = 0;
    }
    if (min == 0 && (check_order(tab) != 0))
    {
        tab = ft_pb(tab, tab_b);
        tab = ft_algo_3_arg(tab, tab_b);
        return (ft_pa(tab, tab_b));
    }
    if (max == 0)
        tab = ft_ra(tab, 4, 0);
    min = ft_min_in_tab(tab, (tab_size(tab)));
    min = ft_min_in_tab(tab, (tab_size(tab)));
    if (min == 1)
    {
        tab = ft_sa(tab, 0);
        tab = ft_algo_4_arg(tab, tab_b);
    }
    min = ft_min_in_tab(tab, (tab_size(tab)));
    if (min == 4)
        tab = ft_rra(tab, 4, 0);
    while (min > 1)
    {
        tab = ft_ra(tab, 4, 0);
        min--;
    }
    if (min == 0 && (check_order(tab) != 0))
    {
        tab = ft_pb(tab, tab_b);
        tab = ft_algo_3_arg(tab, tab_b);
        return(ft_pa(tab, tab_b));
    }
    while (tab_size(tab_b) > 0)
        ft_pa(tab, tab_b);
    if (check_order(tab) != 0)
        return (ft_algo_4_arg(tab, tab_b));
    return (tab);
}

int *ft_algo_5_arg(int *tab, int *tab_b)
{
    int min;
    int max;
    int check;
    int i;

    i = 0;
    max = ft_bigger_in_tab(tab, 5);
    check = check_order(tab);
    if (check == 0)
        return (tab);
    if (max == 0)
        tab = ft_ra(tab, 6, 0);
    if (max == 1)
    {
        tab = ft_sa(tab, 0);
        return (ft_algo_5_arg(tab, tab_b));
    }
    min = ft_min_in_tab(tab, 5);
    if (min == 1)
        tab = ft_sa(tab, 0);
    min = ft_min_in_tab(tab, 5);
    if (min == 0 && (check_order(tab) != 0))
    {
        tab = ft_pb(tab, tab_b);
        tab = ft_algo_4_arg(tab, tab_b);
        return (ft_pa(tab, tab_b));
    }
    while (min > 1)
    {
        if (min > 3)
            tab = ft_rra(tab, 6, 0);
        else
            tab = ft_ra(tab, 6, 0);
        min = ft_min_in_tab(tab, 5);
    }
    return(ft_algo_5_arg(tab, tab_b));
    

    //return (tab);
}

int *big_algo(int *tab, int *tab_b, int size)
{/*
    int max;

    max = ft_bigger_in_tab(tab, (size + 2));
    printf("maxxxxx==%d && sizeeeeee==%d\n", max, size);
    if (max != size)
    {
        while(max >= 0)
        {
           // printf("ra ici\n");
            tab = ft_ra(tab, (size + 1), 0);
            max--;
        }
        if (check_order(tab) == 0)
        {
            printf("popopopo\n");
            return(tab);
        }
        return(ft_algo_5_arg(tab, tab_b));
    }
    else
    {
        size--;
        printf("laaaaaa\n");
        return(big_algo(tab, tab_b, size));
    }*/


    int min;
    int check;
    int i;
    int size_down;
    min = ft_min_in_tab(tab, size);
    check = check_order(tab);
    size_down= size;
    i = 0;

                printf("==========%d==========MIIIIIIIN\n", min);
            printf("chckkkk==%d\n", check);
            printf("sizeeuuuuu==%d\n", size);

    if (check == 0)
        return(tab);
    else
    {
        while (tab)
        {
            i = 0;
            if (check == 0)
                break;
            if(min != 0)
            {
                if (min == 1)
                    tab = ft_sa(tab, 0);
                else if (min > (size/2))
                    tab = ft_rra(tab, (size + 1), 0);
                else if (min < (size/2))
                    tab = ft_ra(tab, (size+1), 0);
                min = ft_min_in_tab(tab, size);
                printf("mineuuu== %d\n", min);
            }
            if (min == 0)
            {
                tab = ft_pb(tab, tab_b);
                printf("o\n");
                i++;
                min = ft_min_in_tab(tab, size);
            }
            check = check_order(tab);
        }
        tab = ft_pa(tab, tab_b);
        tab = ft_pa(tab, tab_b);
        return (tab);

    }
    return (tab);
}
