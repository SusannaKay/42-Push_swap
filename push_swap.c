/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:47:02 by skayed            #+#    #+#             */
/*   Updated: 2025/04/15 08:34:59 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_all(t_node **a, t_node **b, int *array, int mode)
{
	if (mode == 1)
		write(2, "Error\n", 6);
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	if (array)
		free(array);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		*array;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	array = parse_prompt(argc, argv, NULL, &size);
	if (!array || check_array(array, size) || array == NULL)
		return(free_all(&a, &b, array, 1), 1);
	fill_stack(&a, array, size);
	sort_stack(&a, &b, size);
	free_all(&a, &b, array, 0);
	return (0);
}
