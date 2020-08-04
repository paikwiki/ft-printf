/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/04 21:42:50 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		current_idx;
	int		total_len;

	va_start(ap, format);
	current_idx = 0;
	total_len = 0;
	while (format[current_idx] != '\0')
	{
		if (format[current_idx] != '%')
		{
			ft_putchar_fd(format[current_idx], 1);
			total_len = total_len + 1;
		}
		else
		{
			str = va_arg(ap, char *);
			ft_putstr_fd(str, 1);
			total_len = total_len + ft_strlen(str);
		}
		++current_idx;
	}
	va_end(ap);

	return (total_len);
}
