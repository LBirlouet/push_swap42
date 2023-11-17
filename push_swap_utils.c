/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:58:47 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/17 12:28:54 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_nbr(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return(-1);
    while (str[i])
    {
        if (str[i] == '\0')
            return(1);
        if (str[i] == '-' && i > 0)
            return (-1);
        if (!((str[i] >= '0' && str[i] <= '9')|| str[i] == '-'))
            return (-1);
        i++;
    }
}

int verif_arg(int argc, char **argv)
{
    int i;
    int verif;
    i = 1;
    if (argc < 2)
        return (-1);
    while (i < argc)
    {
        verif = ft_is_nbr(argv[i]);
        if (verif == -1)
            return (-1);
        i++;
    }
    return (0);
}

int ft_conv_char_int(char *str)
{
    int ret;
    int i;

    i = 0;
    ret = 0;
    if(str[0] == '-')
    {
        i = 1;
        while(str[i] != '\0')
        {
            ret = (ret * 10) + (str[i] - 48);
            i++;
        }
        return (ret * - 1);
    }
    else
    {
        while(str[i] != '\0')
        {
            ret = (ret * 10) + (str[i] - 48);
            i++;
        }
    }
    return (ret);
}

int tab_size(int *tab)
{
    int i;

    i = 0;
    while(tab[i])
        i++;
    return (i);
}

int *verif_diff(int *tab, int i, int j)
{
    if(tab_size(tab) == 2)
    {
        if(tab[0] == tab[1])
            return (NULL);
        else
            return (tab);
    }
    if (tab[0] == tab[tab_size(tab)- 1])
        return (NULL);
    while(tab[i])
    {
        j = 1 + i;
        while(j <= tab_size(tab))
        {
            if (tab[i] == tab[j])
                return (NULL);
            else
                j++;
        }
        i++;
    }
    return (tab);
}
