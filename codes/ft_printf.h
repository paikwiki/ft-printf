/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:43:46 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 20:04:54 by cbaek            ###   ########.fr       */
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
typedef struct	s_note
{
	char	flag;
	int		width;
	int		prcs;
	int		is_dot;
	char	type;
	int		space;
	int		zero;
	int		arg;
}				t_note;

int				ft_printf(const char *format, ...);
char			*itoa_abs(int arg);
size_t			putnchar(char chr, size_t cnt);
size_t			put_c_type(int arg, t_note *note);
size_t			put_percent_type(t_note *note);
size_t			put_p_type(unsigned long arg, t_note *note);
size_t			put_s_type(char *arg, t_note *note);
size_t			put_di_type(int arg, t_note *note);
size_t			put_u_type(unsigned int arg, t_note *note);
size_t			put_xx_type(unsigned int arg, char *base, t_note *note);
#endif
