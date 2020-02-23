/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:20:00 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/30 19:19:20 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcspn(const char *str, const char *charset)
{
	int len;
	int	i;
	int	j;

	len = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
		{
			if (str[i] == charset[j])
				break ;
		}
		if (str[i] == charset[j])
			break ;
		len++;
	}
	return (len);
}
