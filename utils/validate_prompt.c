/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:13:00 by skayed            #+#    #+#             */
/*   Updated: 2025/04/02 18:07:53 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prompt_isalpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

long long int	ft_atoil(const char *str, int *error)
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

t_node	*validate_prompt(char *str, t_node *a)
{
	char	**split;
	int		*array;
	int		error;
	int		i;

	i = 0;
	error = 0;
	split = ft_split(str, ' ');
	if (!split)
		return (free(split), NULL);
	array = malloc(matrix_size(split) * sizeof(int));
	while (*split)
	{
		array[i++] = ft_atoil(*split++, &error);
		if (error)
			return (ft_free_matrix(split), error); //liberare array
	}
	return (a);
}
