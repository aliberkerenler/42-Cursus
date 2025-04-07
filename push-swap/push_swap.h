/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:42:34 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/07 17:42:39 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    int				value;
    int				index;
    struct s_list	*next;
}				t_list;

t_list	*new_item(int value);
t_list	*last_node(t_list *head);
void	add_back(t_list **stack, t_list *new);
int		size(t_list *head);

void	check_args(int argc, char **argv);

int		is_sorted(t_list **stack);
int		get_distance(t_list **stack, int index);
int		get_min(t_list **stack, int val);

void	radix_sort(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	index_stack(t_list **stack);

int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverseRotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

void	free_stack(t_list **stack);
void	*free_result(char **result, int index);
void	ft_free(char **str);

int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);

#endif

