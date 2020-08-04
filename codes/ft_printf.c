/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/04 20:59:09 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1);
		else
		{
			str = va_arg(ap, char *);
			ft_putstr_fd(str, 1);
		}
		++format;
	}
	va_end(ap);

	return (0);
}
