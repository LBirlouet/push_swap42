/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:20 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/18 10:55:20 by lbirloue         ###   ########.fr       */
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
    free(tab);
    free(tab_b);
}
