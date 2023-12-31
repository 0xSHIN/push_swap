/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:46:29 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/06 17:41:41 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoll(char *nbr, t_stack **a, char **t)
{
	int				i;
	int				s;
	long long int	res;

	i = 0;
	s = 1;
	res = 0;
	while (nbr[i])
	{
		while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
			i++;
		if (nbr[i] == '-' || nbr[i] == '+')
			if (nbr[i++] == '-')
				s = -1;
		while (nbr[i] >= '0' && nbr[i] <= '9')
		{
			res = res * 10 + nbr[i] - '0';
			if (s == 1 && res > 2147483647)
				return (freetab(t), free_s(a), ft_printf("Error\n"), exit(1), 0);
			else if (s == -1 && - res < -2147483648)
				return (freetab(t), free_s(a), ft_printf("Error\n"), exit(1), 0);
			i++;
		}
	}
	return (res * s);
}

int	validate_arg(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '-' && j != 0) || (tab[i][j] == '-' && !tab[i][j
					+ 1]))
				return (1);
			if ((tab[i][j] < '0' || tab[i][j] > '9') && (tab[i][j] != '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	has_doubles(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*runner;

	current = *stack_a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (free_s(stack_a), 1);
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*tmp;
	int		last;

	if (!*stack_a)
		return (ft_printf("Error\n"), exit(1), 1);
	tmp = *stack_a;
	last = tmp->value;
	while (tmp)
	{
		if (tmp->value < last)
			return (0);
		last = tmp->value;
		tmp = tmp->next;
	}
	return (free_s(stack_a), 1);
}
