/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:56:55 by skayed            #+#    #+#             */
/*   Updated: 2025/04/04 17:23:08 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bubble_sort(int *array, int size)
{
	int swapped;
	int i;
	int tmp;
	
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1] && i + 1 < size - 1)
				{
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					swapped = 1;
				}
				i++;
		}
	}
}
static int is_dup(int *array, int size)
{
	int i;
	int j;

	i = 1;
	while ( i < size - 1)
	{
		j = 0;
		while (j < i)
		{
			if (array[i] == array[j])
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}

static int is_sort(int *array, int size)
{
	int i;

	i = 0;
	while ( i < size - 1)
	{
		if (array[i] > array[i + 1])
			return(0);
		i++;
	}
	return(1);	
}

int sort_array(int *array, int size)
{
	if (is_dup(array, size) || is_sort(array, size))
		return (1);
	bubble_sort(array, size);
	return (0);
}
