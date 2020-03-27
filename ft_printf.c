/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/27 21:34:46 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	check_params(const char *str, ...)
{
	if (str)
		;
	return (1);
}

static int	get_pholders(t_list *lst_pholder, const char *str)
{
	if (!str || !lst_pholder)
		return (0);
	return (1);
}

void	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		arg_len;

	// 1. 연결리스트인 `ph_list`와 `lst_args`를 만든다.
	t_list	*ph_list;

	if((ph_list = (t_list *)malloc(sizeof(t_list))) == 0)
		return ;
	ph_list->content = 0;
	// 2. `ph_list`에 자리지정자를 담는다.
	pholderfinder(&ph_list, str, ft_strlen(str));

	arg_len = ft_lstsize(ph_list);
	// 3. `lst_args`에 가변인자를 담는다.
	va_start(ap, str);
	while (arg_len > 0)
	{
		va_arg(ap, int);
	}
	va_end(ap);
	// 4. `ph_list`의 길이와 `lst_args`의 길이를 비교한다. `ph_list`의 길이가 더 길면 오류 반환
	// 5. 문자열을 `%`를 만날 때까지 출력한다.
	// 6. `%`를 만나면 다음 문자가 `%`인지 체크해서 맞을 경우 `%`처리 로직 수행(`%` 한번만 찍기)
	// 7. 자리지정자로 판단되면 `ph_list`와 `lst_args`로부터 하나씩 꺼내와서 데이터 처리/출력한다.
	// 8. 5~7번 과정을 문자열 끝까지 진행한다.
	free(ph_list);


}
