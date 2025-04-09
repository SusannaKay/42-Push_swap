/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:29:42 by skayed            #+#    #+#             */
/*   Updated: 2025/04/09 16:26:28 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((a > b) && (b < c) && (a < c))
		sa(stack);
	else if ((a > b) && (b > c))
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
	{
		ra(stack);
	}
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

static void	push_min(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*min_node;
	int		min;

	tmp = *a;
	min = tmp->value;
	min_node = tmp;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	while ((*a)->value != min_node->value)
		ra(a);
	pb(a, b);
}

static void	sort_five(t_node **a, t_node **b, int size)
{
	push_min(a, b);
	if (size == 5)
		push_min(a, b);
	sort_three(a);
	pa(a, b);
	if (size == 5)
		pa(a, b);
}

void	sort_stack(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
	{
		sort_five(a, b, size);
	}
	else
		radix_sort(a, b);
}
