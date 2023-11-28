/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:20 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/28 12:40:53 by lbirloue         ###   ########.fr       */
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

int	ft_put_in_tab(int argc, char **argv, int *tab)
{
	ssize_t	i;
	ssize_t	conv;

	i = 0;
	while ((argc - 1) > i)
	{
		conv = ft_conv_char_int(argv[i + 1]);
		if (conv > INT_MAX || conv < INT_MIN)
			return (-1);
		tab[i] = conv;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	*tab_b;
	int	verif;
	int	asuppppp;

	asuppppp = argc - 1;
	if (argc <= 2)
		return (-1);
	if ((verif_arg(argc, argv) == -1))
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
	printf("%p %p\n", &tab_b[0], &tab[4]);

	verif = ft_put_in_tab(argc, argv, tab);

	// int	i;
	// i = 0;
	// while (asuppppp > 0)
	// {
	// 	printf("==tab[%d]==%d\n", i, tab[i]);
	// 	i++;
	// 	asuppppp--;
	// }
	if (verif == -1)
	{
        ft_error_msg();
		return(-1);
	}
	verif = dispatch(tab, tab_b, argc);
	if (verif == -1)
	{
		ft_error_msg();
		return (-1);
	}
	//   ft_free(tab);
	/*  tessssstttttt   */
	// int	i;
	// i = 0;
	// // while (asuppppp > 0)
	// // {
	// // 	printf("==tab[%d]==%d\n", i, tab[i]);
	// // 	i++;
	// // 	asuppppp--;
	// // }
	free(tab);
	free(tab_b);
	return (0);
}
