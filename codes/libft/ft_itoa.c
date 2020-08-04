/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:03:56 by chPaik            #+#    #+#             */
/*   Updated: 2020/03/07 22:00:43 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	getdigit(long long nbr)
{
	long long	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		getsign(long long nbr)
{
	char		sign;
	if (nbr >= 0)
		sign = '+';
	else
	{
		nbr *= -1;
		sign = '-';
	}
	return (sign);
}

char		*ft_itoa(int n)
{
	char		*str;
	char		sign;
	long long	ln;
	long long	memsize;

	ln = (long long)n;
	sign = getsign(ln);
	if (ln < 0)
		ln *= -1;
	memsize = getdigit(ln) + ((sign - 43) / 2);
	if ((str = (char *)malloc(sizeof(char) * (memsize + 1))) == 0)
		return 0;
	str[memsize--] = 0;
	if (ln == 0)
		str[0] = ln + '0';
	while (ln > 0)
	{
		str[memsize--] = (ln % 10) + '0';
		ln /= 10;
	}
	if (sign == '-')
		str[memsize] = sign;
	return str;
}
