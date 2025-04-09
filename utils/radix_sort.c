/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:12:34 by skayed            #+#    #+#             */
/*   Updated: 2025/04/09 16:07:56 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	num_max(t_node **a)
{
	int		max;
	t_node	*tmp;

	tmp = *a;
	max = (*a)->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

static int	find_bit(int num)
{
	int	bits;

	bits = 0;
	while (num)
	{
		num >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	index_max;
	int	bit;
	int	i;
	int	j;

	index_max = num_max(a);
	bit = find_bit(index_max);
	i = 0;
	while (i < bit)
	{
		j = 0;
		while (j <= index_max)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
