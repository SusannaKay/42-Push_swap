/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:59:11 by skayed            #+#    #+#             */
/*   Updated: 2025/04/05 16:03:26 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
static void	get_index(t_node *a, int *sorted, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == sorted[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	fill_stack(t_node **a, int *array, int size)
{
	t_node	*new;
	int		*sorted;
	int		i;

	i = 0;
	sorted = bubble_sort(array, size);
	while (i < size)
	{
		new = malloc(sizeof(t_node));
		if (!new)
		{
			return ;
		}
		new->value = array[i];
		new->index = 0;
		new->next = NULL;
		append_node(a, new);
		i++;
	}
	get_index(*a, sorted, size);
}
