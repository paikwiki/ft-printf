/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/16 17:44:55 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static	int count_placeholder(const char *str)
{
	char	*haystack;
	int		cnt;

	haystack = ft_strdup(str);
	cnt = 0;

	if (*haystack == '%')
	{
		cnt++;
		haystack++;
	}
	while (*haystack)
	{
		if (*haystack == '%' && *(haystack - 1) != '%')
			cnt++;
		haystack++;
	}
	return cnt;
}

void	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		arg;
	int		arg_cnt;

	idx = 0;
	arg_cnt = count_placeholder(str);
	va_start(ap, str);
	while (idx < arg_cnt)
	{
		arg = va_arg(ap, int);
		ft_putstr_fd((char *)str, 1);
		ft_putnbr_fd(arg, 1);
		ft_putendl_fd("", 1);
		idx++;
	}
	va_end(ap);
}
