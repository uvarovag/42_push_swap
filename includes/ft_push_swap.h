/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:05:30 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/21 18:02:03 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

typedef struct		s_stack
{
	int				val;
	int				i;
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*max_sort;
	int				len_a;
	int				len_b;
	int				opt_a;
	int				opt_b;
	int				opt_pl;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				cmd_print;
	int				cmds_cnt;
	int				flag_v;
}					t_stacks;

int					cmd_apply_s(t_stack **stack);
int					cmd_apply_r(t_stack **stack);
int					cmd_apply_rr(t_stack **stack);
int					cmd_apply_p(t_stack **from, t_stack **to);
void				cmd_apply_cnt(char *com, int cnt, t_stacks *sts);

int					st_set_tmp_cmds(t_stacks *sts, t_stack *tmp_b);
void				st_copy_tmp_to_opt_cmds(t_stacks *sts);

void				set_index(t_stack *st);
t_stack				*get_max_sort(t_stack *st);
int					node_iter_to_up(int st_len, int node_i);
int					get_node_place_i(t_stack *st, int node_val);
int					node_b_to_a_count(int a, int b, int place_b);

void				st_a_norm(t_stacks *sts);
void				st_a_to_b(t_stacks *sts);
void				node_b_to_a(t_stacks *sts);
void				st_b_to_a(t_stacks *sts);
void				st_a_min_to_top(t_stacks *sts);

t_stack				*stack_pop_front(t_stack **stack);
t_stack				*stack_pop_back(t_stack **stack);

void				stack_push_back(t_stack **stack, t_stack *new);
void				stack_push_front(t_stack **stack, t_stack *new);
t_stack				*stack_push_back_int(t_stack **stack, int val);

t_stack				*create_new_node(int val);
t_stack				*get_last_node(t_stack *st);
int					get_count_nodes(t_stack *st);
t_stacks			*create_stacks(int ac, char **av);

int					stacks_free(t_stacks **sts, int ret_val);
void				put_error(t_stacks **sts, int ret_val);

int					is_valid_int(int val_i, char *val_c);
int					is_not_dupl(t_stack *st, int val);
int					is_sort_stacks(t_stacks *sts);
void				print_stack(t_stacks *sts);

#endif
