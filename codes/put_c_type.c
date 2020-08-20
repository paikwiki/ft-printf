/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:47:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 15:10:26 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t put_c_type(int arg, t_struct *fields)
{
	// TODO: field 처리
	if (fields->flag == '-')
		ft_putchar_fd('-', 1);

	ft_putchar_fd((char)arg, 1);
	return (1);
}
