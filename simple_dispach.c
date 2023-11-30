/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_dispach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:51:08 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/30 17:49:41 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dispatch(int *tab_a, int *tab_b, int argc)
{
	if (verif_diff(tab_a, 0, 0, (argc - 2)) == NULL)
    {
		return (-1);
    }
	else if (check_order(tab_a, (argc - 1)) == 0)
    {
		return (0);
    }
	else if (argc == 3)
    {
		tab_a = ft_algo_2_arg(tab_a);
    }
	else if (argc == 4)
		tab_a = ft_algo_3_arg(tab_a, tab_b);
	else if (argc == 5)
		tab_a = ft_algo_4_arg(tab_a, tab_b);
	else if (argc == 6)
		tab_a = ft_algo_5_arg(tab_a, tab_b);
	else
		tab_a = big_algo(tab_a, tab_b, (argc - 1), (argc-1));
	/*cheeeeeckkkkkkkkkkkkkkkkkkkkkkkkkkk*/
//	int check = check_order(tab_a);
//	printf("checkkk = %d\n", check);
	return (0);
}