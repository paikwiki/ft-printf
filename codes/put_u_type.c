/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:14:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 12:15:47 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_u_type(unsigned int arg)
{
	char	*str;

	str = ft_strdup(ft_uitoa_base(arg, DECIMAL));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
