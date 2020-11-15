/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:04:51 by mobouzar          #+#    #+#             */
/*   Updated: 2019/12/05 19:25:02 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_ceil(int nbr1, int nbr2)
{
	int result;

	result = 0;
	if (nbr1 % nbr2 == 0)
		result = (int)(nbr1 / nbr2);
	else
		return (((int)(nbr1 / nbr2)) + 1);
	return (result);
}
