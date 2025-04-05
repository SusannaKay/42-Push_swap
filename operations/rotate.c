/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 03:11:13 by skayed            #+#    #+#             */
/*   Updated: 2025/04/05 15:26:25 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a)
{
	t_node	*head;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	*a = (*a)->next;
	while (head != NULL)
		head = head->next;
	head->next = *a;
	(*a)->next = NULL;
	ft_printf("ra\n");
}
void	rb(t_node **b)
{
	t_node	*head;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	head = *b;
	*b = (*b)->next;
	while (head != NULL)
		head = head->next;
	head->next = *b;
	(*b)->next = NULL;
	ft_printf("rb\n");
}
void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}