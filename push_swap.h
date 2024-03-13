/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:05:38 by tlay              #+#    #+#             */
/*   Updated: 2024/03/13 16:40:48 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// void				ft_print_stack(t_stack *to_print, char *when);

char				**my_split(char *s, char c);
char				*my_strjoin(char *s1, char *s2);
char				*ft_free_strjoin(char *all_av, char *new_av);

// ft_stack_init.c
void				ft_stack_init(char **av, t_stack **stack_a);

// parsing.c
int					ft_parsing(char *table);

// parsing_utils.c
int					ft_check_doubles(t_stack *stack_a, int new);
int					ft_check_digit(char *str);
int					ft_check_overflow(long new);
int					ft_check_overflow_ull(unsigned long long new, char *table);
int					ft_check_missing_space(char *table);

// ft_atol.c
long				ft_atol(char *str);
long				ft_size_int(long nb);

// ft_atoll.c
long long			ft_atoll(char *str);

// ft_atoull.c
unsigned long long	ft_atoull(char *str);
unsigned long long	ft_size_ull(unsigned long long nb);

// ft_error.c
void				ft_error(t_stack *stack_a, char *all_av, char **table);
void				ft_free(char **table);

// lst_utils1.c
t_stack				*my_lstnew(int value);
void				my_lstadd_back(t_stack **lst, t_stack *new);
void				my_lstclear(t_stack **lst);
void				my_lstadd_front(t_stack **lst, t_stack *new);
void				my_lstdelone(t_stack *lst);

// lst_utils2.c
int					my_lstsize(t_stack *stack);
t_stack				*my_lstlast(t_stack *stack);
int					ft_min(t_stack *stack);
int					ft_max(t_stack *stack);
int					ft_find_index(t_stack *stack, int nb);

// commands.c
void				ft_sa(t_stack **stack_a, int j);
void				ft_sb(t_stack **stack_b, int j);
void				ft_ss(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_pa(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_ra(t_stack **stack_a, int j);
void				ft_rb(t_stack **stack_b, int j);
void				ft_rr(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_rra(t_stack **stack_a, int j);
void				ft_rrb(t_stack **stack_b, int j);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b, int j);

// small_sort.c
void				ft_small_sort(t_stack **stack_a);

// algo.c
void				ft_sort(t_stack **stack_a, t_stack **stack_b);

// algo_utils.c
int					ft_med_index(t_stack *stack);
void				ft_nb_on_top_a(t_stack **stack_a, int nb);
void				ft_nb_on_top_b(t_stack **stack_b, int nb);
int					ft_check_sorted_a(t_stack *stack_a);
int					ft_check_sorted_b(t_stack *stack_b);

// ft_find_place.c
int					ft_find_place_b(t_stack *stack_b, int nb);
int					ft_find_place_a(t_stack *stack_a, int nb);

// ft_cost.c
void				ft_apply_case(t_stack **stack_a, t_stack **stack_b);

// ft_cost_cases.c
int					ft_case_rrarrb(t_stack *stack_a, t_stack *stack_b, int nb);
int					ft_case_rarb(t_stack *stack_a, t_stack *stack_b, int nb);
int					ft_case_rarrb(t_stack *stack_a, t_stack *stack_b, int nb);
int					ft_case_rrarb(t_stack *stack_a, t_stack *stack_b, int nb);

// ft_cost_apply.c
int					ft_apply_rrarrb(t_stack **stack_a, t_stack **stack_b,
						int cheap_node);
int					ft_apply_rarb(t_stack **stack_a, t_stack **stack_b,
						int cheap_node);
int					ft_apply_rrarb(t_stack **stack_a, t_stack **stack_b,
						int cheap_node);
int					ft_apply_rarrb(t_stack **stack_a, t_stack **stack_b,
						int cheap_node);

// checker_utils.c
void				ft_checker_error(t_stack **stack_a, t_stack **stack_b,
						char *line);

#endif