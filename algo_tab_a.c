/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tab_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:00:37 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/17 12:30:47 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *ft_algo_2_arg(int *tab)
{
    int first;
    int second;

    first = tab[0];
    second = tab[1];
    printf("==%d\n", first);
    printf("==%d\n", second);
    if (first > second)
        tab = ft_sa(tab, 0);
    else
        return (tab);
}

int *ft_sa(int *tab, int y)
{
    int tempo;
    tempo = tab[0];
    tab[0] = tab[1];
    tab[1] = tempo;
    if(y != 1)
        write (1, "sa\n", 3);
    return (tab);
}

int *ft_ra(int *tab, int argc, int y)
{
    int tempo;
    int first;
    int i;

    i = 1;
    first = tab[0];
    while (i < (argc - 1))
    {
        tempo = tab[i];
        tab[i - 1] = tempo;
        i++;
    }
    tab[argc - 2] = first;
    if(y != 1)
        write (1, "ra\n", 3);
    return(tab);
}

int *ft_rra(int *tab, int argc, int y)
{
    int tempo;
    int last;
    int i;

    i = argc - 2;
    last = tab[argc - 2];
    while (i > 0)
    {
        tempo = tab[i - 1];
        tab [i] = tempo;
        i--;
    }
    tab[0] = last;
    if(y != 1)
        write (1, "rra\n", 4);
    return (tab);
}
