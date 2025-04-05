/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:59:11 by skayed            #+#    #+#             */
/*   Updated: 2025/04/04 17:37:24 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	append_node(t_node **stack, t_node *new)
{
	t_node	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
static void index_stack(int value, int i, t_node **a)
{
	int i;

	i = 0;
	while(i < size)
	{
		
	}
}

void	fill_stack(t_node **a, int *array, int size)
{
	t_node	*new;
	int		i;

	i = 0;
	while (i < size)
	{
		new = malloc(sizeof(t_node));
		if (!new)
		{
			free_stack(a);
			return ;
		}
		new->value = array[i];
		new->index = 0;      
		new->next = NULL;
		append_node(a, new);
		i++;
	}
}



