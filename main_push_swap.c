/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:20 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/23 13:20:22 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(int *tab)
{
	free(tab);
	tab = NULL;
	return ;
}

void	ft_error_msg(void)
{
	write(1, "Error\n", 6);
	return ;
}

void	ft_put_in_tab(int argc, char **argv, int *tab)
{
	int	i;
	int	conv;

	i = 0;
	while ((argc - 1) > i)
	{
		conv = ft_conv_char_int(argv[i + 1]);
		tab[i] = conv;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	*tab_b;
	int	verif;
	int	asuppppp;
	int	i;

	asuppppp = argc - 1;
	if ((verif_arg(argc, argv) == -1) || argc <= 2)
	{
        ft_error_msg();
		return (-1);
	}
	tab = malloc((argc - 1) * sizeof(int));
	if (!tab)
		return (-1);
	tab_b = malloc((argc - 1) * sizeof(int));
	if (!tab_b)
		return (-1);
	ft_put_in_tab(argc, argv, tab);
	verif = dispatch(tab, tab_b, argc);
	if (verif == -1)
		return (-1);
	//   ft_free(tab);
	/*  tessssstttttt   */
	i = 0;
	while (asuppppp > 0)
	{
		printf("==tab[%d]==%d\n", i, tab[i]);
		i++;
		asuppppp--;
	}
	free(tab);
	free(tab_b);
	return (0);
}
