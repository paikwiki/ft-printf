/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:13:28 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 12:14:32 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_d_type(int arg)
{
	char	*str;

	str = ft_strdup(ft_itoa(arg));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
