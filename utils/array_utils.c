/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:56:55 by skayed            #+#    #+#             */
/*   Updated: 2025/04/07 07:38:26 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*dup_array(int *array, int size)
{
	int *sorted;
	int i;
	
	sorted = malloc(sizeof(int) * size);
	i = 0;
	if (!sorted)
		return(NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = array[i];
		i++;
	}
	return(sorted);
}
int	*bubble_sort(int *array, int size)
{
	int	*sorted;
	int	tmp;
	int	i;
	int	swapped;

	swapped = 1;
	sorted = dup_array(array, size);
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
	return (sorted);
}
static int is_dup(int *array, int size)
{
    int i, j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[i] == array[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int	is_sort(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_array(int *array, int size)
{
	if (is_dup(array, size) || is_sort(array, size))
		return (1);
	return (0);
}
