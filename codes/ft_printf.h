/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:43:46 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 16:06:41 by cbaek            ###   ########.fr       */
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
# define ERROR -1
# define PRINT_NULL "(null)"
typedef struct	s_struct
{
	char	flag;
	int		width;
	int		prcs;
	int		is_dot;
	char	type;
}				t_struct;

typedef struct	s_putcounts
{
	int	space;
	int	zero;
	int	arg;
}				t_putcounts;

int				ft_printf(const char *format, ...);
void			init_putcounts(t_putcounts *pcnt);
size_t			putnchar(char chr, size_t cnt);
size_t			put_c_type(int arg, t_struct *fields);
size_t			put_percent_type(t_struct *fields);
size_t			put_p_type(unsigned long arg, t_struct *fields);
size_t			put_s_type(char *arg, t_struct *fields);
size_t			put_di_type(int arg, t_struct *fields);
size_t			put_u_type(unsigned int arg, t_struct *fields);
size_t			put_xx_type(unsigned int arg, char *base, t_struct *fields);
#endif
