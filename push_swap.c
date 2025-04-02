/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:47:02 by skayed            #+#    #+#             */
/*   Updated: 2025/04/02 16:55:18 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int main(int argc, char *argv[])
{
	t_node *a;
	t_node *b;
	
	b = NULL;
	
	if (argc == 2)
	{
		a = validate_prompt(argv[1]);
		if (!a)
		{
			ft_printf("Error\n");
			return(1);
		}
	}
	else
	{
		
	}
	
}