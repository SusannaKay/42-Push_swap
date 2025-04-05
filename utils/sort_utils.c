/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:29:42 by skayed            #+#    #+#             */
/*   Updated: 2025/04/05 16:05:47 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_node **a)
{
	t_node	*current;

	current = *a;
	if (current->value > current->next->value)
		sa(a);
	if (current->next->value > current->next->next->value)
	{
		rra(a);
		if (current->value > current->next->value)
			sa(a);
	}
}

static void	push_min(t_node **a, t_node **b)
{
	int	min;

	min = (*a)->value;
	while (*a)
	{
		if ((*a)->value < min)
			min = (*a)->value;
		*a = (*a)->next;
	}
	pb(a,b);
}
static void	sort_five(t_node **a, t_node **b, int size)
{
	push_min(a, b);
	if (size == 5)
		push_min(a,b);
	sort_three(a);
	pb(a,b);
	if(size == 5)
		pb(a,b);
}
void	sort_stack(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sa(a);
	if (size == 3)
		sort_three(a);
	if (size == 4 || size == 5)
		sort_five(a, b, size);
	else
		radix_sort(a, b);
}
