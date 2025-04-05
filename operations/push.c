/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:56:21 by skayed            #+#    #+#             */
/*   Updated: 2025/04/05 15:28:41 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*b = tmp;
		ft_printf("pa\n");
	}
}
void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*a = tmp;
		ft_printf("pb\n");
	}
}
