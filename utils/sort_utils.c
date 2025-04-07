/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:29:42 by skayed            #+#    #+#             */
/*   Updated: 2025/04/07 07:21:18 by skayed           ###   ########.fr       */
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
        ra(a); // Ruota finché il minimo non è in cima
    pb(a, b); // Sposta il minimo nello stack b
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
