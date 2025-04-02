/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:00:20 by skayed            #+#    #+#             */
/*   Updated: 2025/03/29 04:05:21 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*tmp;
	t_node	*last;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next)
		{
			last = tmp;
			tmp = tmp->next;
		}
		last->next = NULL;
		tmp->next = *a;
		*a = tmp;
		ft_printf("rra\n");
	}
}

void	rrb(t_node **b)
{
	t_node	*tmp;
	t_node	*last;

	if (*b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next)
		{
			last = tmp;
			tmp = tmp->next;
		}
		last->next = NULL;
		tmp->next = *b;
		*b = tmp;
		ft_printf("rrb\n");
	}
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
