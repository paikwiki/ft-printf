/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:43:46 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 12:39:56 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define TYPES "cspdiuxX%"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

typedef struct	s_struct
{
	char	flag;
	int		width;
	int		prcs;
	char	type;
}				t_struct;

int				ft_printf(const char *format, ...);
size_t			put_c_type(int arg);
size_t			put_percent_type();
size_t			put_p_type(unsigned long arg);
size_t			put_s_type(char *arg, t_struct *fields);
size_t			put_d_type(int arg, t_struct *fields);
size_t			put_u_type(unsigned int arg, t_struct *fields);
size_t			put_xx_type(unsigned int arg, char *base, t_struct *fields);
#endif
