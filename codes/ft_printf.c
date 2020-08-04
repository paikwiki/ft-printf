/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/04 20:32:40 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printf(int placeholder_count, ...)
{
	va_list	ap;
	int		args;
	char	*str;

	args = 0;
	va_start(ap, placeholder_count);
	while (args < placeholder_count)
	{
		str = va_arg(ap, char *);
		printf("%s", str);
		++args;
	}
	va_end(ap);

	return (0);
}
