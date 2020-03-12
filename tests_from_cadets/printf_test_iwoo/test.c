/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:39:02 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 03:22:32 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <assert.h>

static void	test_printf_no_format(void)
{
	int res;
	int	std_res;

	res = ft_printf("a\n");
	std_res = printf("a\n");
	assert(res == std_res && "test_printf_no_option");
}

static void	test_printf_c_format(void)
{
	int		res;
	int		std_res;
	char	c;

	c = 'c';
	res = ft_printf("ab%c\n", c);
	std_res = printf("ab%c\n", c);
	assert(res == std_res && "test_printf_c_format");
}

static void	test_printf_s_format(void)
{
	int		res;
	int		std_res;
	char	*str;

	str = "abcdef";
/*	res = ft_printf("%s\n", str);
	std_res = printf("%s\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 0");
	printf("------------------\n");
	res = ft_printf("%.3s\n", str);
	std_res = printf("%.3s\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 1");
	printf("------------------\n");
	res = ft_printf("%.0s\n", str);
	std_res = printf("%.0s\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 2");
	printf("------------------\n");
	res = ft_printf("%.*s\n", 3, str);
	std_res = printf("%.*s\n", 3, str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 3");
	printf("------------------\n");
	res = ft_printf("%*.*s\n", 5, 3, str);
	std_res = printf("%*.*s\n", 5, 3, str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 4");
	printf("------------------\n");
	res = ft_printf("%*.0s\n", 5, str);
//	std_res = printf("%*.0s\n", 5,str);
	printf("res:     %d\n", res);
//	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 5"); 

	str = "abcdef";
	printf("ft_printf:\n");
	res = ft_printf("%.*s", -3, str);
	printf("printf:\n");
	std_res = printf("%.*s\n", -3, str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 6");

	str = "abcdef";
	res = ft_printf("%-*.*s\n", -7, -3, str);
	std_res = printf("%-*.*s\n", -7, -3, str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 7"); */

	str = "abcdef";
	printf("ft_printf: \n");
	res = ft_printf("%.*s", 3, str);
	printf("\nprintf: \n");
	std_res = printf("%.*s", 3, str);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 7");

	str = "abcdef";
	printf("ft_printf: \n");
	res = ft_printf("%-*.*s", 7, 3, str);
	printf("\nprintf: \n");
	std_res = printf("%-*.*s", 7, 3, str);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_s_format 7");

}

static void	test_printf_p_format(void)
{
	int		res;
	int		std_res;
	char	*str;
	int		d;

/*	str = "abcdef";
	res = ft_printf("%p\n", str);
	std_res = printf("%p\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_p_format 0");
	printf("------------------\n");

	res = ft_printf("%20p\n", str);
	std_res = printf("%20p\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_p_format 1");
	printf("------------------\n");

	res = ft_printf("%-20p\n", str);
	std_res = printf("%-20p\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_p_format 2");
	printf("------------------\n");

	str = NULL;
	res = ft_printf("%p\n", str);
	std_res = printf("%p\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_p_format 3");
	printf("------------------\n"); 

	str = NULL;
	res = ft_printf("%.p\n", str);
	std_res = printf("%.p\n", str);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_p_format 4");
	printf("------------------\n"); 

	d = 1234;
	res = ft_printf("%.2p\n", d);
	std_res = printf("%.2p\n", d);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_p_format 4");
	printf("------------------\n"); */

}

static void	test_printf_d_format(void)
{
	int		res;
	int		std_res;
	int		nb;

	nb = 2147483647;
	res = ft_printf("%d\n", nb);
	std_res = printf("%d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 0");
	printf("------------------\n");

	res = ft_printf("%20d\n", nb);
	std_res = printf("%20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 1");
	printf("------------------\n");

	res = ft_printf("%-20d\n", nb);
	std_res = printf("%-20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 2");
	printf("------------------\n");

	res = ft_printf("%.20d\n", nb);
	std_res = printf("%.20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 3");
	printf("------------------\n");

	res = ft_printf("%30.20d\n", nb);
	std_res = printf("%30.20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 3");
	printf("------------------\n");

	res = ft_printf("%020d\n", nb);
	std_res = printf("%020d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 4");
	printf("------------------\n");

	nb = -2147483648;
	res = ft_printf("%d\n", nb);
	std_res = printf("%d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 5");
	printf("------------------\n");

	res = ft_printf("%20d\n", nb);
	std_res = printf("%20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 6");
	printf("------------------\n");

	res = ft_printf("%-20d\n", nb);
	std_res = printf("%-20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 7");
	printf("------------------\n");

	res = ft_printf("%.20d\n", nb);
	std_res = printf("%.20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 8");
	printf("------------------\n");

	res = ft_printf("%30.20d\n", nb);
	std_res = printf("%30.20d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 8");
	printf("------------------\n");

	res = ft_printf("%020d\n", nb);
	std_res = printf("%020d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 9");
	printf("------------------\n");

	nb = 042;
	res = ft_printf("%d\n", nb);
	std_res = printf("%d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 10");
	printf("------------------\n");

	nb = 0xff;
	res = ft_printf("%d\n", nb);
	std_res = printf("%d\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 10");
	printf("------------------\n");

}

static void	test_printf_i_format(void)
{
	int		res;
	int		std_res;
	int		nb;

/*	nb = 2147483647;
	res = ft_printf("%i\n", nb);
	std_res = printf("%i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 0");
	printf("------------------\n");

	res = ft_printf("%20i\n", nb);
	std_res = printf("%20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 1");
	printf("------------------\n");

	res = ft_printf("%-20i\n", nb);
	std_res = printf("%-20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 2");
	printf("------------------\n");

	res = ft_printf("%.20i\n", nb);
	std_res = printf("%.20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 3");
	printf("------------------\n");

	res = ft_printf("%30.20i\n", nb);
	std_res = printf("%30.20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 3");
	printf("------------------\n");

	res = ft_printf("%020i\n", nb);
	std_res = printf("%020i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 4");
	printf("------------------\n");

	nb = -2147483648;
	res = ft_printf("%i\n", nb);
	std_res = printf("%i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 5");
	printf("------------------\n");

	res = ft_printf("%20i\n", nb);
	std_res = printf("%20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 6");
	printf("------------------\n");

	res = ft_printf("%-20i\n", nb);
	std_res = printf("%-20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 7");
	printf("------------------\n");

	res = ft_printf("%.20i\n", nb);
	std_res = printf("%.20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 8");
	printf("------------------\n");

	res = ft_printf("%30.20i\n", nb);
	std_res = printf("%30.20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 8");
	printf("------------------\n");

	res = ft_printf("%-30.20i\n", nb);
	std_res = printf("%-30.20i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 9");
	printf("------------------\n");

	res = ft_printf("%020i\n", nb);
	std_res = printf("%020i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 10");
	printf("------------------\n");

	nb = 042;
	res = ft_printf("%i\n", nb);
	std_res = printf("%i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 11");
	printf("------------------\n");

	nb = 0xff;
	res = ft_printf("%i\n", nb);
	std_res = printf("%i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 12");
	printf("------------------\n");

	nb = -216;
	res = ft_printf("%-10.5i\n", nb);
	std_res = printf("%-10.5i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 13");
	printf("------------------\n");

	nb = 34;
	res = ft_printf("%08.5i\n", nb);
	std_res = printf("%08.5i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 14");
	printf("------------------\n");

	nb = 34;
	res = ft_printf("%8.5i\n", nb);
	std_res = printf("%8.5i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 15");
	printf("------------------\n");

	nb = 34;
	res = ft_printf("%0-8.5i\n", nb);
	std_res = printf("%0-8.5i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 16");
	printf("------------------\n"); 

	nb = 8475;
	res = ft_printf("%08.3i\n", nb);
	std_res = printf("%08.3i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 17");
	printf("------------------\n"); 

	nb = 4242;
	res = ft_printf("%.2i\n", nb);
	std_res = printf("%.2i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 18");
	printf("------------------\n");

	nb = 4242;
	res = ft_printf("%.1i\n", nb);
	std_res = printf("%.1i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 19");
	printf("------------------\n");

	nb = 4242;
	res = ft_printf("%.0i\n", nb);
	std_res = printf("%.0i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 20");
	printf("------------------\n");

	nb = 0;
	res = ft_printf("%.0i\n", nb);
	std_res = printf("%.0i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 21"); 
	printf("------------------\n"); 

	nb = 0;
	res = ft_printf("%.i\n", nb);
	std_res = printf("%.i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 22");
	printf("------------------\n"); */

	nb = 0;
	res = ft_printf("%-5.i\n", nb);
	std_res = printf("%-5.i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 22");
	printf("------------------\n");

	nb = 0;
	res = ft_printf("%05.i\n", nb);
	std_res = printf("%05.i\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_i_format 23");
	printf("------------------\n");
}

static void	test_printf_u_format(void)
{
	int					res;
	int					std_res;
	unsigned int		nb;

/*	nb = 42;
	res = ft_printf("%u\n", nb);
	std_res = printf("%u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 0");
	printf("------------------\n");

	res = ft_printf("%10u\n", nb);
	std_res = printf("%10u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 1");
	printf("------------------\n");

	res = ft_printf("%010u\n", nb);
	std_res = printf("%010u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 2");
	printf("------------------\n");

	res = ft_printf("%-10u\n", nb);
	std_res = printf("%-10u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 3");
	printf("------------------\n");

	nb = 2147483648;
	res = ft_printf("%u\n", nb);
	std_res = printf("%u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 4");
	printf("------------------\n");

	res = ft_printf("%020u\n", nb);
	std_res = printf("%020u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 5");
	printf("------------------\n");

	res = ft_printf("%20u\n", nb);
	std_res = printf("%20u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 6");
	printf("------------------\n");

	res = ft_printf("%-20u\n", nb);
	std_res = printf("%-20u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 7");
	printf("------------------\n");

	res = ft_printf("%.20u\n", nb);
	std_res = printf("%.20u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 8");
	printf("------------------\n");

	res = ft_printf("%30.20u\n", nb);
	std_res = printf("%30.20u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 8");
	printf("------------------\n");

	nb = 042;
	res = ft_printf("%u\n", nb);
	std_res = printf("%u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 9");
	printf("------------------\n");

	nb = 0xff;
	res = ft_printf("%u\n", nb);
	std_res = printf("%u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 10");
	printf("------------------\n"); */

	nb = 43;
	res = ft_printf("%05u\n", nb);
	std_res = printf("%05u\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 10");
	printf("------------------\n");

}

static void	test_printf_x_format(void)
{
	int					res;
	int					std_res;
	unsigned int		nb;

	nb = 42;
	res = ft_printf("%x\n", nb);
	std_res = printf("%x\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 0");
	printf("------------------\n");

	nb = 0xff;
	res = ft_printf("%x\n", nb);
	std_res = printf("%x\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 1");
	printf("------------------\n");
}

static void	test_printf_X_format(void)
{
	int					res;
	int					std_res;
	unsigned int		nb;

	nb = 42;
	res = ft_printf("%X\n", nb);
	std_res = printf("%X\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 0");
	printf("------------------\n");

	nb = 0xff;
	res = ft_printf("%X\n", nb);
	std_res = printf("%X\n", nb);
	printf("res:     %d\n", res);
	printf("std_res: %d\n", std_res);
	assert(res == std_res && "test_printf_d_format 1");
	printf("------------------\n");
}

static void	test_printf_percent_format(void)
{
	int res;
	int	std_res;

	res = ft_printf("%5%\n");
	//std_res = printf("%5%\n");
	printf("res:     %d\n", res);
//	printf("std_res: %d\n", std_res);
//	assert(res == std_res && "test_printf_d_format 0");
	printf("------------------\n");
}

static void	test_multi_arg(void)
{
	int					res;
	int					std_res;
	unsigned int		nb;
	char				c;
	char				*str;

	c = 'a';
	str = "ABC";
	nb = 42;
	res = ft_printf("%c %c %s %s %d %d %i %i %x %x %X %X %%\n", c, c, str, str, nb, nb, nb, nb, nb, nb, nb, nb);
	std_res = printf("%c %c %s %s %d %d %i %i %x %x %X %X %%\n", c, c, str, str, nb, nb, nb, nb, nb, nb, nb, nb);
}

static void	test_for_pft2019(void)
{
	int		 res;
	int		std_res;
	char	*str;

	str = NULL;
/*	res = ft_printf("%5");
	printf("res:     %d\n", res);
	printf("------------------\n");

	res = ft_printf("%.s", str);
	printf("res:     %d\n", res);
	printf("------------------\n"); 

	res = ft_printf("hello %s.", str);
	printf("\n");
	std_res = printf("hello %s.\n", str);
	printf("res:     %d\n", res);
	printf("std_res:  %d\n", res);
	printf("------------------\n"); 

	res = ft_printf("%.03s", str);
	printf("\n");
	std_res = printf("%.03s", str);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res:  %d\n", res);
	printf("------------------\n");

	res = ft_printf("%.09s", str);
	printf("\n");
	std_res = printf("%.09s", str);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res:  %d\n", res);
	printf("------------------\n");  */


static char *s_hidden = "hi low\0don't print me lol\0";
/*	res = ft_printf("%.03s", s_hidden);
	printf("\n");
	std_res = printf("%.03s", s_hidden);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res:  %d\n", res);
	printf("------------------\n");  

	res = ft_printf("%3.s", s_hidden);
	printf("\n");
	std_res = printf("%3.s", s_hidden);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res:  %d\n", res);
	printf("------------------\n"); 

	res = ft_printf("%00s", s_hidden);
	printf("\n");
	std_res = printf("%00s", s_hidden);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res:  %d\n", res);
	printf("------------------\n"); 

	res = ft_printf("%0-0s", s_hidden);
	printf("\n");
	std_res = printf("%0-0s", s_hidden);
	printf("\n");
	printf("res:     %d\n", res);
	printf("std_res:  %d\n", res);
	printf("------------------\n"); */



}


int			main(void)
{
	char *str;
	int	res;
	int	res2;
	char	c;

	c = 'z';
	str = "01234";
/*	printf("======test 0======\n");
	test_printf_no_format();
	printf("======test 2======\n");
	test_printf_c_format(); */
	printf("======test 3======\n"); 
	test_printf_s_format();  
/*	printf("======test 4======\n"); 
	test_printf_p_format();  
	printf("======test 5======\n"); 
	test_printf_d_format();  
	printf("======test 6======\n"); 
	test_printf_i_format(); 
	printf("======test 7======\n"); 
	test_printf_u_format(); 
	printf("======test 8======\n"); 
	test_printf_X_format(); 
	printf("======test 9======\n");
	test_printf_percent_format(); 
	printf("======test 10======\n");
	test_multi_arg(); 
	printf("======test 11======\n");
	test_for_pft2019(); */


	return (0);
}
