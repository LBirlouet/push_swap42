/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:48:05 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/23 10:28:02 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		main(int argc, char **argv);
void	ft_error_msg(void);
int		ft_is_nbr(char *str);
int		verif_arg(int argc, char **argv);
int		ft_conv_char_int(char *str);
int		ft_min_in_tab(int *tab, int size);
int		ft_bigger_in_tab(int *tab, int size);
/*  ALGOOOOOOO  */
int		*ft_algo_2_arg(int *tab);
int		*ft_algo_3_arg(int *tab, int *tab_b);
int		*ft_algo_4_arg(int *tab, int *tab_b);
int		*ft_algo_5_arg(int *tab, int *tab_b);
int		*big_algo(int *tab, int *tab_b, int size);
/*  FIN AGLOOOO */
int		tab_size(int *tab);
int		*verif_diff(int *tab, int i, int j);
/*check l'ordre*/
int		check_order(int *tab);
/*......*/
int		dispatch(int *tab_a, int *tab_b, int argc);
/*  operations  */
int		*ft_sa(int *tab, int y);
int		*ft_ra(int *tab, int argc, int y);
int		*ft_rra(int *tab, int argc, int y);
/*  b   */
int		*ft_sb(int *tab_b, int y);
int		*ft_rb(int *tab_b, int argc, int y);
int		*ft_rrb(int *tab_b, int argc, int y);
/*same time*/
int		*ft_ss(int *tab, int *tab_b);
int		*ft_rr(int *tab, int *tab_b, int argc);
int		*ft_rrr(int *tab, int *tab_b, int argc);
/*diverse*/
int		*ft_pa(int *tab_a, int *tab_b);
int		*ft_pa_norm(int *tab, int tempo);
int		*ft_pb(int *tab_a, int *tab_b);
int		*ft_pb_norm(int *tab, int tempo);

#endif