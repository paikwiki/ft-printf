/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:17:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 17:58:31 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	// printf("$%20c$\n", 'a');
	// printf("$%020c$\n", 'a');
	// printf("$%10.6x$\n", 113801);
	// printf("$%6.8x$\n", 113801);
	// printf("$%10.4x$\n", 113801);
	// printf("$%4.6x$\n", 113801);
	// printf("$%4.3x$\n", 113801);
	// printf("$%3.4x$\n", 113801);
	// printf(":%+d:\n", 123);
	// printf(":%+d:\n", -123);

	// printf(":%4X:\n",3);
	// printf(":%04X:\n",3);

	// // `
	// printf(":%'d:\n", 123456789); // xsi, not working

	// // #
	// printf(":%#f:\n", 123456.0);
	// printf(":%f:\n", 123456.0);
	// printf(":%#f:\n", 123456789.123);
	// printf(":%f:\n", 123456789.123);
	// printf(":%#x:\n", 123456789);
	// printf(":%x:\n", 123456789);

	// width field
	// printf(":% -*.*d:\n", 8, 4, 24);
	// printf(":% -8.4d:\n", 24);
	// printf(":% -+12.4%:\n");
	// printf(":%4d:\n", 123);
	// printf(":%4d:\n", 12);
	// printf(":%-4X:\n",3);
	// printf(":%4d:\n", 123456);
	// printf(":%4d:\n", 12345678);
	// printf(":%*d:\n", 5, 10);
	// printf(":%*d:%*d:\n", 5, 10, 5, 3);
	// printf(":%-d:\n", 123);
	// printf(":%-d:\n", -123);
	// printf(":%jd:\n", (long)4294967296);
	// #include <limits.h>
	// printf(":%ld:\n", (long)INT_MIN);
	// printf(":%d:\n", -2147483648);
	// printf(":%d:\n", -2147483647 - 1);P
	// printf(":%d:\n", (int)-2147483648);

	printf(":%s:\n", "hello");
	return (0);
}
