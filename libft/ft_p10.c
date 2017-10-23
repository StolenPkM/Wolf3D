/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:58:53 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/14 17:10:38 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_p10(int n)
{
	int		result;

	result = 1;
	if (n == 0)
		return (1);
	while (n--)
		result *= 10;
	return (result);
}
