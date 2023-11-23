/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tab_same_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:38:25 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/23 10:25:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_ss(int *tab, int *tab_b)
{
    tab = ft_sa(tab, 1);
    tab_b = ft_sb(tab_b, 1);
    write(1, "ss\n", 3);
    return (tab);
}

int *ft_rr(int *tab, int *tab_b, int argc)
{
    tab = ft_ra(tab, argc, 1);
    tab_b = ft_rb(tab_b, argc, 1);
    write(1, "rr\n", 3);
    return (tab);
}

int *ft_rrr(int *tab, int *tab_b, int argc)
{
    tab = ft_rra(tab, argc, 1);
    tab_b = ft_rrb(tab_b, argc, 1);
    write(1, "rrr\n", 4);
    return (tab);
}
