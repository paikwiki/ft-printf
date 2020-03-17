/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/17 15:34:02 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	check_params(const char *str, ...)
{
	if (str)
		;
	return (1);
}

static int	count_placeholder(const char *str)
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

	// placeholders에 자리지정자를 담는다
	// placeholders: 연결리스트
	arg_cnt = count_placeholder(str);

	// args에 가변인자를 담는다.
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

	// placeholders와 args의 오류를 체크한다.

	// 메인 로직을 수행한다

}
