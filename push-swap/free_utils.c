/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:41:36 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/07 17:41:36 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	ft_free(char **str)
{
    int	i;

    i = 0;
    while (str[i])
        i++;
    while (i >= 0)
    {
        free(str[i]);
        i--;
    }
    free(str);
}

void	free_stack(t_list **stack)
{
    t_list	*head;
    t_list	*tmp;

    head = *stack;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(stack);
}

void	*free_result(char **result, int index)
{
    if (!result[index])
    {
        while (index >= 0)
        {
            free(result[index]);
            index--;
        }
        free(result);
        return (NULL);
    }
    return (result);
}