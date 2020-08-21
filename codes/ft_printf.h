/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:43:46 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 11:07:24 by cbaek            ###   ########.fr       */
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

typedef struct	s_putcounts
{
	int	space;
	int	zero;
	int	arg;
}				t_putcounts;

int				ft_printf(const char *format, ...);
size_t			putnchar(char chr, size_t cnt);
size_t			put_c_type(int arg, t_struct *fields);
size_t			put_percent_type(t_struct *fields);
size_t			put_p_type(unsigned long arg, t_struct *fields);
size_t			put_s_type(char *arg, t_struct *fields);
size_t			put_di_type(int arg, t_struct *fields);
size_t			put_u_type(unsigned int arg, t_struct *fields);
size_t			put_xx_type(unsigned int arg, char *base, t_struct *fields);
#endif
