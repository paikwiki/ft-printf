/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:09:45 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 12:41:19 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_s_type(char *arg, t_struct *fields)
{
	char	*str;

	// TODO: field 처리
	if (fields->flag == '-')
		ft_putchar_fd('-', 1);
	str = ft_strdup(arg);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
