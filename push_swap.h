/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:48:05 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/17 12:28:48 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int main(int argc, char **argv);
int ft_is_nbr(char *str);
int verif_arg(int argc, char **argv);
int ft_conv_char_int(char *str);
int *ft_algo_2_arg(int *tab);
int tab_size(int *tab);
int *verif_diff(int *tab, int i, int j);
/*  operations  */
int *ft_sa(int *tab, int y);
int *ft_ra(int *tab, int argc, int y);
int *ft_rra(int *tab, int argc, int y);
/*  b   */
int *ft_sb(int *tab_b, int y);
int *ft_rb(int *tab_b, int argc, int y);
int *ft_rrb(int *tab_b, int argc, int y);
/*same time*/
int *ft_ss(int *tab, int *tab_b);
int *ft_rr(int *tab, int *tab_b, int argc);
int *ft_rrr(int *tab, int *tab_b, int argc);
/*diverse*/
int *ft_pa(int *tab_a, int *tab_b);
int *ft_pa_norm(int *tab, int tempo);
int *ft_pb(int *tab_a, int *tab_b);
int *ft_pb_norm(int *tab, int tempo);


#endif