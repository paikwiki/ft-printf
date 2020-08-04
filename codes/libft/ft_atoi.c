/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 09:23:24 by cbaek             #+#    #+#             */
/*   Updated: 2020/02/29 11:25:07 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = -(str[i++] - 44);
	if (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 0)
			sign = 1;
		while (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i++] - '0');
	}
	return (sign * result);
}
