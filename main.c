/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:20 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/17 15:48:41 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free(int *tab)
{
    free(tab);
    tab == NULL;
    return ;
}

void    ft_put_in_tab(int argc, char **argv, int *tab)
{
    int i;
    i = 0;
    int conv;
    while ((argc - 1) > i)
    {
        conv = ft_conv_char_int(argv[i + 1]);
        tab[i] = conv;
        i++;
    }
}

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

int *ft_algo_big(int *tab, int *tab_b)
{
    int min;

    min = ft_min_in_tab(tab);
    printf("tabbb min = %d\n", min);
    int i = 0;
    if(ft_min_in_tab(tab) == 0)
    {
        tab = ft_pb(tab, tab_b);
        tab = ft_algo_3_arg(tab, tab_b);
        tab = ft_pa(tab, tab_b);
    }
    else
    {
        while(min >= i)
        {
            tab = ft_pb(tab, tab_b);
            i++;
        }
        tab = ft_algo_3_arg(tab, tab_b);
        while(i > 0)
        {
            tab = ft_pa(tab, tab_b);
            i--;
        }
    }
    return (tab);
}

int    dispatch(int *tab_a, int *tab_b, int argc)
{
    if (verif_diff(tab_a, 0, 0) == NULL)
        return (-1);
    else if (argc == 3)
        tab_a = ft_algo_2_arg(tab_a);
    else if (argc == 4)
        tab_a = ft_algo_3_arg(tab_a, tab_b);
    else if (argc > 5)
        tab_a = ft_algo_big(tab_a, tab_b);
    /*cheeeeeckkkkkkkkkkkkkkkkkkkkkkkkkkk*/
    int check = check_order(tab_a);
    printf("checkkk = %d\n", check);
    return (0);
}

int main(int argc, char **argv)
{
    int *tab;
    int *tab_b;
    int verif;

    if (verif_arg(argc, argv) == -1 || argc <= 2)
        return (-1);
    tab = malloc((argc-1) * sizeof(int));
    if (!tab)
        return(-1);
    tab_b = malloc((argc-1) * sizeof(int));
    if (!tab_b)
        return(-1);
    ft_put_in_tab(argc, argv, tab);
    verif = dispatch(tab, tab_b, argc);
    if (verif == -1)
        return (-1);

 //   ft_free(tab);



    /*  tessssstttttt   */
    int i;
    i = 0;
    while (tab[i])
    {
        printf("==tab[%d]==%d\n", i, tab[i]);
        i++;
    }
}
