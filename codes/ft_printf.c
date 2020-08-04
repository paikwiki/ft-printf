/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/05 01:18:41 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdio.h>

static const char	*get_placeholder(const char *format, int *idx)
{
	char	*placeholder;
	int		len;
	int		ph_idx;

	len = 1;
	while (ft_strchr(TYPES, format[*idx + len++]) == 0) /* 형식 필드를 만날때까지 while 실행 */
		;
	placeholder = (char *)malloc(sizeof(char) * (len + 1));
	placeholder[len] = '\0';
	ph_idx = 0;
	while (len > ph_idx)
	{
		placeholder[ph_idx] = format[*idx + ph_idx];
		++ph_idx;
	}
	*idx = *idx + (len - 1);
	return ((const char *)placeholder);
}

static int	proc_ft_printf(const char *format, va_list ap)
{
	char		*str;
	const char	*placeholder;
	int			idx;
	int			total_len;

	idx = 0;
	total_len = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] != '%')
		{
			ft_putchar_fd(format[idx], 1);
			total_len = total_len + 1;
		}
		else
		{
			placeholder = get_placeholder(format, &idx);
			str = va_arg(ap, char *);
			if (ft_strrchr(placeholder, 's') != 0)
				ft_putstr_fd(str, 1);
			total_len = total_len + ft_strlen(str);
		}
		++idx;
	}
	return (total_len);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = proc_ft_printf(format, ap);
	va_end(ap);
	return (len);
}
