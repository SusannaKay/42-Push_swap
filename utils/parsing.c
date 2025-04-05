/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:13:00 by skayed            #+#    #+#             */
/*   Updated: 2025/04/04 17:15:30 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *create_array(int *size, char **matrix)
{
	int i;
	int error;
	char **tmp;
	int *array;
	
	i = 0;
	error = 0;
	array = malloc((*size) * sizeof(int));
	if (!array)
		return(NULL);
	tmp = matrix;
	while(*tmp)
	{
		array[i++] = ft_atoil(*tmp++, &error);
		if (error)
			return (NULL);
	}
	return (array);
}

static int	matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

static void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static int	ft_atoil(const char *str, int *error)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (*error = 1, 0);
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		return (*error = 1, 0);
	return (sign * result);
}

int	*parse_prompt(int argc, char **argv, int *array, int *size)
{
	char	**split;
	int		error;
	int		i;

	i = 0;
	error = 0;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || split[0] == NULL)
			return (NULL);
		*size = matrix_size(split);
		array = create_array(&size, split);
		if (!array)
			return(ft_free_matrix(split), NULL );
	}
	else
	{
		*size = argc - 1;
		array = create_array(&size, argv);
	}
	return (array);
}
