/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:32:50 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/17 10:38:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int main()
{
    int *tab;

    tab = malloc(5 * sizeof(int *));
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 4;
    tab[4] = 5;
    int i;
    i = 0;
    while(tab[i])
    {
        printf("tabbbb[%d] == %d\n", i, tab[i]);
        i++;
    }
    printf("||%d||\n", tab[6]);
    printf("ok");

}