/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/05 15:58:34 by cbaek            ###   ########.fr       */
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
	while (ft_strchr(TYPES, format[*idx + len]) == 0)
		++len;
	placeholder = (char *)malloc(sizeof(char) * (len + 1));
	placeholder[len] = '\0';
	ph_idx = 0;
	while (len >= ph_idx)
	{
		placeholder[ph_idx] = format[*idx + ph_idx];
		++ph_idx;
	}
	*idx = *idx + len;
	return ((const char *)placeholder);
}

static char			*get_typed_arg(const char *placeholder, va_list ap)
{
	char	*str;
	char	ph_type;

	ph_type = placeholder[ft_strlen(placeholder) - 1];
	if (ph_type == 'c')
	{
		if ((str = (char *)malloc(sizeof(char) * 2)) == NULL)
			return (0);
		str[0] = (char)va_arg(ap, int);
		str[1] = '\0';
	}
	else if (ph_type == 's')
		str = ft_strdup(va_arg(ap, char *));
	else if (ph_type == 'd')
		str = ft_strdup(ft_itoa(va_arg(ap, int)));
	else if (ph_type == 'i')
		str = ft_strdup(ft_itoa(va_arg(ap, int)));
	// else if (ph_type == 'p')
	// 	;
	// else if (ph_type == 'u')
	// 	;
	// else if (ph_type == 'x')
	// 	;
	// else if (ph_type == 'X')
	// 	;
	// else if (ph_type == '%')
	// 	;
	else
	{
		if ((str = (char *)malloc(sizeof(char) * 1)) == NULL)
			return (0);
		str[0] = '\0';
	}

	return (str);
}

static int			proc_ft_printf(const char *format, va_list ap)
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
			str = get_typed_arg(placeholder, ap);
			/* TODO: 가져온 str에 형식 필드 외의 다른 필드 적용 */
			ft_putstr_fd(str, 1);
			total_len = total_len + ft_strlen(str);
		}
		++idx;
	}
	return (total_len);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = proc_ft_printf(format, ap);
	va_end(ap);
	return (len);
}
