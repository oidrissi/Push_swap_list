/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:03:29 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 10:03:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b) 
{ 
	int temp;

	temp = *a; 
	*a = *b; 
	*b = temp; 
}  

void	bubblesort(int array[], int n) 
{ 
    int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (array[j] > array [j + 1])
				swap(&array[j], &array[j+1]);
			j++;
		}
		i++;
	}
}
