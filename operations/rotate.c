/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 03:11:13 by skayed            #+#    #+#             */
/*   Updated: 2025/04/07 07:47:33 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(t_node **a)
{
    t_node *first;
    t_node *last;
    
    if (*a == NULL || (*a)->next == NULL)
        return;
    
    first = *a;
    *a = (*a)->next;
    
    last = *a;
    while (last->next != NULL)
        last = last->next;
    
    last->next = first;
    first->next = NULL;
    
    ft_printf("ra\n");
}
void	rb(t_node **b)
{
	t_node *first;
    t_node *last;
    
    if (*b == NULL || (*b)->next == NULL)
        return;
    
    first = *b;
    *b = (*b)->next;
    
    last = *b;
    while (last->next != NULL)
        last = last->next;
    
    last->next = first;
    first->next = NULL;
	ft_printf("rb\n");
}
void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}