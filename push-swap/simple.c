/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:42:55 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/07 17:42:56 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_next_min_case(t_list **stack_a, int min)
{
    if ((*stack_a)->next->index == min)
        sa(stack_a);
    else
        rra(stack_a);
}

static void	sort_3(t_list **stack_a)
{
    t_list	*head;
    int		min;
    int		next_min;

    head = *stack_a;
    min = get_min(stack_a, -1);
    next_min = get_min(stack_a, min);
    if (is_sorted(stack_a))
        return ;
    if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
    else if (head->index == next_min)
        handle_next_min_case(stack_a, min);
    else if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
    int	stack_size;

    if (is_sorted(stack_a) || size(*stack_a) == 0
        || size(*stack_a) == 1)
        return ;
    stack_size = size(*stack_a);
    if (stack_size == 2)
        sa(stack_a);
    else if (stack_size == 3)
        sort_3(stack_a);
    else if (stack_size == 4)
        sort_4(stack_a, stack_b);
    else if (stack_size == 5)
        sort_5(stack_a, stack_b);
}

