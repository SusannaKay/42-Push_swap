/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:47:02 by skayed            #+#    #+#             */
/*   Updated: 2025/04/04 17:33:31 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int main(int argc, char *argv[])
{
	t_node *a;
	t_node *b;
	int *array;
	int size;
	
	b = NULL;
	if (argc < 2)
		return(0);
	array = parse_prompt(argc, argv, array, &size);
	if (!array)
		return(ft_printf("Error\n"), 1);
	if(!sort_array(array, size))
		{free(array);
		return(ft_printf("Error\n"), 1);}
	fill_stack(a, array, size);
	
	free(array);
	return (0);
}
// funzione uscita e libera nodi 