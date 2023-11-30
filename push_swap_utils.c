/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:58:47 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/30 16:40:53 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_is_nbr(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	if (str[i] == '\0')
		return (-1);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (-1);
	if (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
		{
			if (str[i + 1] <= '0' || str[i + 1] > '9')
				return (-1);
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ')
		{
			i++;
		}
	//	printf("|%d|%d|\n", i, size);
		if (i != size)
			return (-1);
	}
	//printf("la\n");
	return (0);
}

int	next_nbr(char *str, int i)
{

	while (str[i] == ' ' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	put_one_str_in_tab(int nbr_arg, char *str, int *tab)
{
	ssize_t	i;
	ssize_t	conv;
	int j;

	i = 0;
	j = 0;
	while ((nbr_arg) > i)
	{
		conv = ft_conv_char_int(&str[j]);
	//	printf("j == %d\n", j);
	//	printf("|%zd|\n", conv);
		if (conv > INT_MAX || conv < INT_MIN)
			return (-1);
		tab[i] = conv;
		j = next_nbr(str, j);
		i++;
	}
	return (0);
}

int arg_counter(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != 0)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			counter ++;
		}
		while (str[i] == ' ')
			i++;
	}
	return (counter);
}

int	verif_one_str(char *str)
{
	int	i;

	i = 0;
	while(str[i] != 0)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
		while (str[i] == ' ')
			i++;
	}
	return (0);
}

int	verif_arg(int argc, char **argv)
{
	int	i;
	int	verif;

	i = 1;
	if (argc < 2)
		return (-1);
	if (argc == 2)
		return (verif_one_str(argv[1]));
	while (i < argc)
	{
		verif = ft_is_nbr(argv[i]);
		if (verif == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_min_in_tab(int *tab, int size)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 0;
	while (size > i)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	i = 0;
	while (tab[i] != min)
		i++;
	return (i);
}

int	ft_bigger_in_tab(int *tab, int size)
{
	int	max;
	int	i;
	int	j;

	max = INT_MIN;
	i = 0;
	j = 0;
	while (size > i)
	{
		if (tab[i] > max)
		{
			max = tab[i];
		}
		i++;
	}
	while (tab[j] != max)
		j++;
	return (j);
}

ssize_t	ft_conv_char_int(char *str)
{
	ssize_t	ret;
	ssize_t	i;

	i = 0;
	ret = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i += 1;
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		{
			ret = (ret * 10) + (str[i] - 48);
			i++;
		}
		return (ret * -1);
	}
	else
	{
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		{
			ret = (ret * 10) + (str[i] - 48);
			i++;
		}
	}
	return (ret);
}

int	tab_size(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*verif_diff(int *tab, int i, int j, int size)
{
	if (tab_size(tab) == 2)
	{
		if (tab[0] == tab[1])
			return (NULL);
		else
			return (tab);
	}
	if (tab[0] == tab[size])
		return (NULL);
	while (tab[i])
	{
		j = 1 + i;
		while (j <= size)
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

int	check_order(int *tab, int size)
{
	int i;
	int verif;
	int tempo;

	i = 0;
	verif = 0;
	tempo = INT_MIN;
	if (tab_size(tab) == 2)
	{
		if (tab[0] < tab[1])
			return (1);
		else
			return (-1);
	}
	while (size > i)
	{
		if (tempo < tab[i])
		{
			tempo = tab[i];
			verif++;
		}
		else
			return (verif);
		i++;
	}
	if (verif != size)
		return (verif);
	else
		return (0);
}