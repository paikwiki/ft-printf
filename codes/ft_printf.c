/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/04 20:43:32 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	count_placeholder(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str++ == '%')
			count++;
	}
	return (count);
}
int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		args;
	char	*str;
	int		placeholder_count = count_placeholder(format);
	args = 0;
	va_start(ap, format);
	while (args < placeholder_count)
	{
		str = va_arg(ap, char *);
		printf("%s", str);
		++args;
	}
	va_end(ap);

	return (0);
}
