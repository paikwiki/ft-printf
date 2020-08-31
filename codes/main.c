/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/31 16:58:36 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	// int	len01;
	// int len02;

	// len01 = 0;
	// len02 = 0;
	// static char *s_hidden = "hi low\0don't print me lol\0";

	// printf("================================= \n");
	// printf("== TEST SECTION 1: Type field  == \n");
	// printf("================================= \n\n");
	// /* test 01 - plain text */
	// printf("====== 01 - plain text ========== \n");
	// len01 = ft_printf("ft_printf : Andy is Free!");
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red is in a jail!");
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is Free!");
	// printf("\n");
	// len02 = printf("   printf : Red is in a jail!");
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 02 - s */
	// printf("====== test 02 - s ========== \n");
	// len01 = ft_printf("ft_printf : %s is %s", "Andy", "free!");
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %s", "Red", "in a jail!");
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %s", "Andy", "free!");
	// printf("\n");
	// len02 = printf("   printf : %s is %s", "Red", "in a jail!");
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 03 - d */
	// printf("====== test 03 - d ========== \n");
	// len01 = ft_printf("ft_printf : %s is %d", "Andy", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %d", "Red", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %d", "Andy", 100);
	// printf("\n");
	// len02 = printf("   printf : %s is %d", "Red", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : %s is %d", "Andy", INT_MAX);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %d", "Red", INT_MIN);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %d", "Andy", INT_MAX);
	// printf("\n");
	// len02 = printf("   printf : %s is %d", "Red", INT_MIN);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 04 - c */
	// printf("====== test 04 - c ========== \n");
	// len01 = ft_printf("ft_printf : %c is %c", 'D', 'F');
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %c is %c", 'C', 'J');
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %c is %c", 'D', 'F');
	// printf("\n");
	// len02 = printf("   printf : %c is %c", 'C', 'J');
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 05 - % */
	// printf("====== test 05 - %% ========== \n");
	// len01 = ft_printf("ft_printf : %% is %%");
	// ft_printf("\nlen01: %d\n", len01);

	// len02 = printf("   printf : %% is %%");
	// printf("\nlen02: %d\n", len02);

	// /* test 06 - u */
	// printf("====== test 06 - u ========== \n");
	// len01 = ft_printf("ft_printf : u: %u", 1);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : u: %u", -1);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : u: %u", 1);
	// printf("\n");
	// len02 =    printf("   printf : u: %u", -1);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 07 - p */
	// printf("====== test 07 - p ========== \n");
	// int temp = 0;
	// len01 = ft_printf("ft_printf : p: %p", &temp);
	// ft_printf("\nlen01: %d\n", len01);

	// len02 =    printf("   printf : p: %p", &temp);
	// printf("\nlen02: %d\n", len02);

	// /* test 08 - x */
	// printf("====== test 08 - x ========== \n");
	// len01 = ft_printf("ft_printf : x: %x", 255);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : x: %x", 4080);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : x: %x", 255);
	// printf("\n");
	// len02 =    printf("   printf : x: %x", 4080);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 09 - X */
	// printf("====== test 09 - X ========== \n");
	// len01 = ft_printf("ft_printf : X: %X", 255);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : X: %X", 4080);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : X: %X", 255);
	// printf("\n");
	// len02 =    printf("   printf : X: %X", 4080);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : X: %X", INT_MAX);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : X: %X", INT_MIN);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : X: %X", INT_MAX);
	// printf("\n");
	// len02 =    printf("   printf : X: %X", INT_MIN);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// printf("================================= \n");
	// printf("== TEMPORARY TEST == \n");
	// printf("================================= \n");


	// ft_printf("%*.*s\n",10 ,6 ,"abcde");
	// printf("%*.*s\n",10 ,6 ,"abcde");
	// ft_printf("%*.*s\n",6 ,8 ,"abcde");
	// printf("%*.*s\n",6 ,8 ,"abcde");
	// ft_printf("%*.*s\n",10 ,4 ,"abcde");
	// printf("%*.*s\n",10 ,4 ,"abcde");
	// ft_printf("%*.*s\n",4 ,6 ,"abcde");
	// printf("%*.*s\n",4 ,6 ,"abcde");
	// ft_printf("%*.*s\n",4 ,3 ,"abcde");
	// printf("%*.*s\n",4 ,3 ,"abcde");
	// ft_printf("%*.*s\n",3 ,4 ,"abcde");
	// printf("%*.*s\n",3 ,4 ,"abcde");

	// ft_printf("%*.*d\n",10 ,6 ,23452);
	// printf("%*.*d\n",10 ,6 ,23452);
	// ft_printf("%*.*d\n",6 ,8 ,23452);
	// printf("%*.*d\n",6 ,8 ,23452);
	// ft_printf("%*.*d\n",10 ,4 ,23452);
	// printf("%*.*d\n",10 ,4 ,23452);
	// ft_printf("%*.*d\n",4 ,6 ,23452);
	// printf("%*.*d\n",4 ,6 ,23452);
	// ft_printf("%*.*d\n",4 ,3 ,23452);
	// printf("%*.*d\n",4 ,3 ,23452);
	// ft_printf("%*.*d\n",3 ,4 ,23452);
	// printf("%*.*d\n",3 ,4 ,23452);

	// ft_printf("%*.*u\n",10 ,6 ,23452);
	// printf("%*.*u\n",10 ,6 ,23452);
	// ft_printf("%*.*u\n",6 ,8 ,23452);
	// printf("%*.*u\n",6 ,8 ,23452);
	// ft_printf("%*.*u\n",10 ,4 ,23452);
	// printf("%*.*u\n",10 ,4 ,23452);
	// ft_printf("%*.*u\n",4 ,6 ,23452);
	// printf("%*.*u\n",4 ,6 ,23452);
	// ft_printf("%*.*u\n",4 ,3 ,23452);
	// printf("%*.*u\n",4 ,3 ,23452);
	// ft_printf("%*.*u\n",3 ,4 ,23452);
	// printf("%*.*u\n",3 ,4 ,23452);

	// 	ft_printf("%*.*x\n",10 ,6 ,23452);
	// printf("%*.*x\n",10 ,6 ,23452);
	// ft_printf("%*.*x\n",6 ,8 ,23452);
	// printf("%*.*x\n",6 ,8 ,23452);
	// ft_printf("%*.*x\n",10 ,4 ,23452);
	// printf("%*.*x\n",10 ,4 ,23452);
	// ft_printf("%*.*x\n",4 ,6 ,23452);
	// printf("%*.*x\n",4 ,6 ,23452);
	// ft_printf("%*.*x\n",4 ,3 ,23452);
	// printf("%*.*x\n",4 ,3 ,23452);
	// ft_printf("%*.*x\n",3 ,4 ,23452);
	// printf("%*.*x\n",3 ,4 ,23452);

	// ft_printf("%*.*X\n",10 ,6 ,23452);
	// printf("%*.*X\n",10 ,6 ,23452);
	// ft_printf("%*.*X\n",6 ,8 ,23452);
	// printf("%*.*X\n",6 ,8 ,23452);
	// ft_printf("%*.*X\n",10 ,4 ,23452);
	// printf("%*.*X\n",10 ,4 ,23452);
	// ft_printf("%*.*X\n",4 ,6 ,23452);
	// printf("%*.*X\n",4 ,6 ,23452);
	// ft_printf("%*.*X\n",4 ,3 ,23452);
	// printf("%*.*X\n",4 ,3 ,23452);
	// ft_printf("%*.*X\n",3 ,4 ,23452);
	// printf("%*.*X\n",3 ,4 ,23452);

	// int		a = -4;
	// int		b = 0;
	// char	c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";

	// if (
	// 	a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && f == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0 && m == 0 && n == 0 && o == 0 && p == 0 && q == 0 && r == 0 && s == 0 && t == 0 && u == 0)
	// 	;

	// ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d);
	// ft_printf("%*.d", 0, l);
	// printf("$%0d$\n", l);
	// printf("$%0.d$\n", l);
	// printf("$%03d$\n", l);
	// ft_printf("$%0d$\n", l);
	// ft_printf("$%0.d$\n", l);
	// ft_printf("$%03d$\n", l);

	// // printf("$%*d$", -3, 1);
	// int idx = -5;
	// while (idx < 6)
	// {
	// 	printf("$%*d$\n", idx, 1);
	// 	ft_printf("$%*d$\n", idx, 1);
	// 	idx++;
	// }

	// printf("$%.5i$\n", 2);
	// ft_printf("$%.5i$\n", 2);
	// printf("$%.6d$\n", -3);
	// ft_printf("$%.6d$\n", -3);
	// printf("$%8.6d$\n", -3);
	// ft_printf("$%8.6d$\n", -3);
	// printf("$%-8.6d$\n", -3);
	// ft_printf("$%-8.6d$\n", -3);


	// ft_printf("ft_printf : Andy is $%12.6d$\n", 100);
	//    printf("   printf : Andy is $%12.6d$\n", 100);
	// ft_printf("ft_printf : Andy is $%-12.6d$\n", 100);
	//    printf("   printf : Andy is $%-12.6d$\n", 100);
	// ft_printf("ft_printf : Andy is $%012.6d$\n", 100);
	//    printf("   printf : Andy is $%012.6d$\n", 100);

	// /* test 00 - d */
	// printf("====== test 00 - d ========== \n");
	// len01 = ft_printf("ft_printf : %s is %4d", "Andy", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %6d", "Red", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %4d", "Andy", 100);
	// printf("\n");
	// len02 = printf("   printf : %s is %6d", "Red", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 00 - % */
	// printf("====== test 00 - %% ========== \n");
	// len01 = ft_printf("ft_printf : %-8% is %8%");
	// ft_printf("\nlen01: %d\n", len01);

	// len02 = printf("   printf : %-8% is %8%");
	// printf("\nlen02: %d\n", len02);

	// printf("====== test 00 - width, c ========== \n");
	// len01 = ft_printf("ft_printf : $%-8c$", 'a');
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : $%c$", 'a');
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : $%-8c$", 'a');
	// printf("\n");
	// len02 = printf("   printf : $%c$", 'a');
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// printf("====== test 00 - width, p ========== \n");

	// int temp = 0;
	// len01 = ft_printf("ft_printf : $%20p$", &temp);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : $%-20p$", &temp);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : $%20p$", &temp);
	// printf("\n");
	// len02 = printf("   printf : $%-20p$", &temp);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : Andy is $%*.*d$", 123, 456, 100);
	// ft_printf("\n");
	// len01 = ft_printf("ft_printf : Andy is $%123.456d$", 100);
	// ft_printf("\n");
	// len01 = ft_printf("ft_printf : Andy is $%-123.456d$", 100);
	// ft_printf("\n");
	// len01 = ft_printf("ft_printf : Andy is $%0123.456d$", 100);
	// ft_printf("\n");
	// // c,p,%는 그냥 출력
	// // s는 0으로 정밀도를 맞추는 경우만 제외
	// // d,i,u,xX 는 동일하게 동작
	// len01 =    printf("   printf : u: $%20.20u$\n", 1);
	// len01 =    printf("   printf : u: $%20.10u$\n", 1);
	// len01 =    printf("   printf : u: $%10.20u$\n", 1);
	// // len01 = ft_printf("ft_printf : x: $%20.20x$", 255);
	// ft_printf("\n");

	// printf("Test section 1 is ended. Press any key to continue...\n");
	// scanf("lorem");


	// printf("================================= \n");
	// printf("== TEST SECTION 2: Width Field == \n");
	// printf("================================= \n");

	// /* test 01 - d */
	// printf("====== test 03 - d ========== \n");
	// len01 = ft_printf("ft_printf : Andy is $%6d$", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red  is $%6d$", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is $%6d$", 100);
	// printf("\n");
	// len02 = printf("   printf : Red  is $%6d$", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : Andy is $%-6d$", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red  is $%-6d$", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is $%-6d$", 100);
	// printf("\n");
	// len02 = printf("   printf : Red  is $%-6d$", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : Andy is $%06d$", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red  is $%06d$", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is $%06d$", 100);
	// printf("\n");
	// len02 = printf("   printf : Red  is $%06d$", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);


	// printf("$%05%$\n");
	// ft_printf("$%05%$\n");
	// printf("this %s is empty\n", "");
	// ft_printf("this %s is empty\n", "");

	// printf("$%32s$\n", "abc");
	// ft_printf("$%32s$\n", "abc");
	// printf("$%16s$\n", "nark nark");
	// ft_printf("$%16s$\n", "nark nark");
	// printf("$%.3s$\n", "hello");
	// ft_printf("$%.3s$\n", "hello");
	// printf("$%.0s$\n", "hello");
	// ft_printf("$%.0s$\n", "hello");
	// printf("$hello, %20s.$\n", NULL);
	// ft_printf("$hello, %20s.$\n", NULL);
	// printf("$hello, %s.$\n", NULL);
	// ft_printf("$hello, %s.$\n", NULL);
	// ft_printf("%.5s%7s$", "yo", "boi");
	// ft_printf("$%3.s$", "hi low\0don't print me lol\0");
	// int aa = printf("%.5s%7s", "yo", "boi");
	// int bb = ft_printf("%.5s%7s", "yo", "boi");
	// printf("\n%d, %d\n", aa, bb);

	// printf("$%-8.5x$", 34);
	// printf("$%08.5x$\n", 34);
	// printf("$%0-8.5x$", 0);
	// printf("$%0-8.3x$", 8375);
	// printf("%0-2.7x", 3267);

	// printf("%.0x", 0);
	// printf("%.x", 0);
	// printf("%5.0x", 0);
	// printf("%5.x", 0);
	// printf("%-5.0x", 0);
	// printf("%-5.x", 0);

	// ft_printf("%5.p", NULL);
	// printf("%2.9p\n", 1234);
	// printf("%.5p", 0);

	// d
	// ft_printf("%0-8.5d", 34);
	// ft_printf("%0-10.5d", -216);
	// ft_printf("%0-8.5d", 0);
	// ft_printf("%0-8.3d", 8375);
	// ft_printf("%0-8.3d", -8473);
	// ft_printf("%0-3.7d", 3267);
	// ft_printf("%0-3.7d", -2375);
	// ft_printf("%0-3.3d", 6983);
	// ft_printf("%0-3.3d", -8462);
	// ft_printf("%.0d", 0);
	// ft_printf("%.d", 0);
	// ft_printf("%5.0d", 0);
	// ft_printf("%5.d", 0);
	// ft_printf("%-5.0d", 0);
	// ft_printf("%-5.d", 0);

	// final 42 errors

	// ft_printf("%-05%");
	// ft_printf("%00-s", s_hidden);
	// ft_printf("%09s", s_hidden);
	// ft_printf("%-09s", s_hidden);
	// ft_printf("%7u", 33);
	// ft_printf("%3u", 0);
	// ft_printf("%-7u", 33);
	// ft_printf("%-3u", 0);
	// ft_printf("%.5u", 2);
	// ft_printf("%.3u", 0);
	// ft_printf("%05u", 43);
	// ft_printf("%03u", 0);
	// ft_printf("%8.5u", 34);
	// ft_printf("%8.5u", 0);
	// ft_printf("%8.3u", 8375);
	// ft_printf("%3.7u", 3267);
	// ft_printf("%-8.5u", 34);
	// ft_printf("%-8.5u", 0);
	// ft_printf("%-8.3u", 8375);
	// ft_printf("%-3.7u", 3267);
	// ft_printf("%08.5u", 34);
	// ft_printf("%08.5u", 0);
	// ft_printf("%08.3u", 8375);
	// ft_printf("%03.7u", 3267);
	// ft_printf("%0-8.5u", 34);
	// ft_printf("%0-8.5u", 0);
	// ft_printf("%0-8.3u", 8375);
	// ft_printf("%0-3.7u", 3267);
	// ft_printf("%.0u", 0);
	// ft_printf("%.u", 0);
	// ft_printf("%5.0u", 0);
	// ft_printf("%5.u", 0);
	// ft_printf("%-5.0u", 0);
	// ft_printf("%-5.u", 0);
	// ft_printf("%2.9p\n", 1234);
	// ft_printf("%.5p", 0);
	// ft_printf("%d", INT_MIN);
	// //ddd ft_printf("%d", INT_MAX + 1);
	// ft_printf("%i", INT_MIN);
	// //ddd ft_printf("%i", INT_MAX + 1);
	// ft_printf("%%-d 42 == %-d\n", INT_MIN);
	// ft_printf("%.*i", -6, -3);
	// ft_printf("%-*.*s", -7, -3, "yolo");
	// printf("%-05%");
	// printf("%00-s", s_hidden);
	// printf("%09s", s_hidden);
	// printf("%-09s", s_hidden);/

	// printf("%2.9p\n", 1234);
	// printf("%.5p", 0);
	// printf("%09s", s_hidden);



	// d all =============================================================
	// ft_printf("this %d number", 17);
	// ft_printf("this %d number", -267);
	// ft_printf("this %d number", 0);
	// ft_printf("this %d number", 17);
	// ft_printf("this %d number", -267);
	// ft_printf("this %d number", 0);
	// ft_printf("%d", 3);
	// ft_printf("%d", -1);
	// ft_printf("%d", 0);
	// ft_printf("%d",  2147483647);
	// ft_printf("%d", (int)(-2147483678));
	// ft_printf("%7d", 33);
	// ft_printf("%7d", -14);
	// ft_printf("%3d", 0);
	// ft_printf("%5d", 52625);
	// ft_printf("%5d", -2562);
	// ft_printf("%4d", 94827);
	// ft_printf("%4d", -2464);
	// ft_printf("%-7d", 33);
	// ft_printf("%-7d", -14);
	// ft_printf("%-3d", 0);
	// ft_printf("%-5d", 52625);
	// ft_printf("%-5d", -2562);
	// ft_printf("%-4d", 94827);
	// ft_printf("%-4d", -2464);
	// ft_printf("%.5d", 2);
	// ft_printf("%.6d", -3);
	// ft_printf("%.3d", 0);
	// ft_printf("%.4d", 5263);
	// ft_printf("%.4d", -2372);
	// ft_printf("%.3d", 13862);
	// ft_printf("%.3d",-23646);
	// ft_printf("%05d", 43);
	// ft_printf("%07d", -54);
	// ft_printf("%03d", 0);
	// ft_printf("%03d", 634);
	// ft_printf("%04d", -532);
	// ft_printf("%04d", -4825);
	// ft_printf("%8.5d", 34);
	// ft_printf("%10.5d", -216);
	// ft_printf("%8.5d", 0);
	// ft_printf("%8.3d", 8375);
	// ft_printf("%8.3d", -8473);
	// ft_printf("%3.7d", 3267);
	// ft_printf("%3.7d", -2375);
	// ft_printf("%3.3d", 6983);
	// ft_printf("%3.3d", -8462);
	// ft_printf("%-8.5d", 34);
	// ft_printf("%-10.5d", -216);
	// ft_printf("%-8.5d", 0);
	// ft_printf("%-8.3d", 8375);
	// ft_printf("%-8.3d", -8473);
	// ft_printf("%-3.7d", 3267);
	// ft_printf("%-3.7d", -2375);
	// ft_printf("%-3.3d", 6983);
	// ft_printf("%-3.3d", -8462);
	// ft_printf("%08.5d", 34);
	// ft_printf("%010.5d", -216);
	// ft_printf("%08.5d", 0);
	// ft_printf("%08.3d", 8375);
	// ft_printf("%08.3d", -8473);
	// ft_printf("%03.7d", 3267);
	// ft_printf("%03.7d", -2375);
	// ft_printf("%03.3d", 6983);
	// ft_printf("%03.3d", -8462);
	// ft_printf("%0-8.5d", 34);
	// ft_printf("%0-10.5d", -216);
	// ft_printf("%0-8.5d", 0);
	// ft_printf("%0-8.3d", 8375);
	// ft_printf("%0-8.3d", -8473);
	// ft_printf("%0-3.7d", 3267);
	// ft_printf("%0-3.7d", -2375);
	// ft_printf("%0-3.3d", 6983);
	// ft_printf("%0-3.3d", -8462);
	// ft_printf("%.0d", 0);
	// ft_printf("%.d", 0);
	// ft_printf("%5.0d", 0);
	// ft_printf("%5.d", 0);
	// ft_printf("%-5.0d", 0);
	// ft_printf("%-5.d", 0);

	// pft =============================================
	// printf("%% *.5i 42 == |% *.5i|\n", 4, 42); // 공백 필드는 보너스 파트
	// printf("%.*o", -3, 12345); // o 형식 필드는 보너스 파트
	// printf("%.*o", -1, 12345); // o 형식 필드는 보너스 파트
	// printf("%.*o", -1, 0); // o 형식 필드는 보너스 파트

	// mem leaks =========================================
	// int varp = 0;
	// ft_printf("This is a plain text.");
	// ft_printf("c: %c\n", 'c');
	// ft_printf("s: %s\n", "Life is 42.");
	// ft_printf("p: %p\n", &varp);
	// ft_printf("d: Life is %d\n", 42);
	// ft_printf("i: Life is %i\n", 42);
	// ft_printf("u: Life is %u\n", 42);
	// ft_printf("x: 2048 is %x\n", 2048);
	// ft_printf("X: 2048 is %X\n", 2048);
	// ft_printf("Percent is %%.\n");

	// int temp = 0;
	// while (temp == 0)
	// {
	// 	temp = 0;
	// }
	// return (0);

	// // printf_lover_v2 ========================
	// // char	*p = NULL;
	// int p = 0;
	// printf("-->|%-3.p|<--\n", &p);		// -->|0x7ffee99db3dc|<--
	// ft_printf("-->|%-3.p|<--\n", &p);	// -->|0x|<--
	// printf("-->|%-15.p|<--\n", &p);		// -->|0x7f93b1402710 |<--
	// ft_printf("-->|%-15.p|<--\n", &p);	// -->|0x7f93b1402710             |<--
	// printf("-->|%-2.p|<--\n", &p);
	// ft_printf("-->|%-2.p|<--\n", &p);

	// int x = 42;
	// printf("-->|%-4.x|<--\n", x);
	// ft_printf("-->|%-4.x|<--\n", x);

	/*
	Test 4205 (p_neg_prec_star_03) : FAILED.
    First line of code: {return test("%.*p", -3, 0);}
      expected output : "0x0"
      your output     : "0x"
      expected (nonprintable as hex) : "0x0"
      actual   (nonprintable as hex) : "0x"

	Test 4206 (p_neg_prec_star_04) : FAILED.
    First line of code: {return test("%.*p", -1, 0);}
      expected output : "0x0"
      your output     : "0x"
      expected (nonprintable as hex) : "0x0"
      actual   (nonprintable as hex) : "0x"
	  */

	// fix p(lover & pft)============================
	// char	*p = NULL;
	// int zero = 0;
	// int one = 1;
	// ft_printf("exp|0x0|[.] %%.-3p, 0\nres|%.-3p|\n", 0);
	// ft_printf("exp|0x0|[pft] %%.*p, -3, 0\nres|%.*p|\n", -3, 0);
	// ft_printf("exp|0x0|[pft] %%.*p, -1, 0\nres|%.*p|\n", -1, 0);
	// /* 이 아래 테스트는 결과가 제대로 안나옴;; */
	// ft_printf("exp|0xba9876543210|[.] %%-2.p, NULL\nres|%-2.p|\n", &zero);
	// ft_printf("exp|0xba9876543210|[.] %%-2.p, NULL\nres|%-2.p|\n", NULL);
	// ft_printf("exp|0xba9876543210|[lv] %%-2.p, NULL\nres|%-2.p|\n", p);
	// ft_printf("exp|0xba9876543210|[lv] %%-3.p, NULL\nres|%-3.p|\n", p);
	// ft_printf("exp|0xba9876543210 |[lv] %%-15.p, NULL\nres|%-15.p|\n", p);
	// ft_printf("exp|0x |[lv] %%-16.p, NULL\nres|%-16.p|\n", p);=

	// fix x(lover & pft)============================
	// ft_printf("exp |ffffff79|[lv] %%.x, 4294967161\nres |%.x|\n", 4294967161);
	// ft_printf("exp |c6  |[lv] %%-4.0x, 198\nres |%-4.0x|\n", 198);
	// ft_printf("exp |    |[lv] %%-4.0x, 0\nres |%-4.0x|\n", 0);
	// ft_printf("exp |     |[pft] %%5.0x, 0\nres |%5.0x|\n", 0);

	// fix d(lover) sigabort ========================

	// int		a = -4;
	// // int		b = 0;
	// char	c = 'a';
	// int		d = ;
	// int		e = ;
	// // int		f = 42;
	// // int		g = 25;
	// // int		h = 4200;
	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";
	// while (a < 5) //T34-69
	// {
	// 	printf("%d printf   : %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%d ft_printf: %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	printf("%d printf   : %0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%d ft_printf: %0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	printf("%d printf   : %-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%d ft_printf: %-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	printf("%d printf   : %.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%d ft_printf: %.*i,c %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	a++;
	// }
	// printf("%d ft_printf: %.*i,c %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", 0, 0, 8, 0, -12, 0, 123456789, 0, 0, 0, -12345678, 0, 'a', 0, -2147483647, 0, 2147483647);
	// ft_printf("%d ft_printf: %.*i,c %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", 0, 0, 8, 0, -12, 0, 123456789, 0, 0, 0, -12345678, 0, 'a', 0, -2147483647, 0, 2147483647);

	// printf("|%1.d|\n", 0);
	// ft_printf("|%1.d|\n", 0);

	// printf("-->|%-1.d|<--\n", 0);
	// ft_printf("-->|%-1.d|<--\n", 0);
	// printf("-->|%04.*d|<--\n", -4, 198);
	// ft_printf("-->|%04.*d|<--\n", -4, 198);
	// printf("-->|%04.*d|<--\n", -3, 198);
	// ft_printf("-->|%04.*d|<--\n", -3, 198);
	// printf("-->|%04.*d|<--\n", -2, 198);
	// ft_printf("-->|%04.*d|<--\n", -2, 198);
	// printf("-->|%04.*d|<--\n", -2, 198);
	// ft_printf("-->|%04.*d|<--\n", -2, 198);
	// printf("-->|%04.*d|<--\n", -1, 198);
	// ft_printf("-->|%04.*d|<--\n", -1, 198);

	// printf("-->|%04.*d|<--\n", 0, 198);
	// ft_printf("-->|%04.*d|<--\n", 0, 198);
	// printf("-->|%04.*d|<--\n", 1, 198);
	// ft_printf("-->|%04.*d|<--\n", 1, 198);
	// printf("-->|%04.*d|<--\n", 2, 198);
	// ft_printf("-->|%04.*d|<--\n", 2, 198);
	// printf("-->|%04.*d|<--\n", 3, 198);
	// ft_printf("-->|%04.*d|<--\n", 3, 198);

	// printf("-->|%04.4d|<--\n", 198);
	// ft_printf("-->|%04.4d|<--\n", 198);

	// printf("-->|%-4.*d|<--\n", 4, -135);
	// ft_printf("-->|%-4.*d|<--\n", 4, -135);

	// printf("-->|%-4.4d|<--\n", 138);
	// ft_printf("-->|%-4.4d|<--\n", 138);

	// printf("-->|%0.*d|<--\n", 4, -135);
	// ft_printf("-->|%0.*d|<--\n", 4, -135);

	// printf("-->|%0*.*d|<--\n", 4, -4, -135);
	// ft_printf("-->|%0*.*d|<--\n", 4, -4, -135);

	// printf("-->|%-1.*d|<--\n", -4, 0);
	// ft_printf("-->|%-1.*d|<--\n", -4, 0);

	// printf("-->|%-1.d|<--\n", 0);
	// ft_printf("-->|%-1.d|<--\n", 0);

	// printf("%d\n", printf("-->|%-4.x|<--\n", 198));
	// printf("%d\n", ft_printf("-->|%-4.x|<--\n", 198));

	// // printf("-->|%-4.x|<--\n", 4294967161);
	// ft_printf("-->|%-4x|<--\n", 4294967161);

	// ft_printf("|%-4.*d|\n", 4, -135);


// printf("%d\n", printf("-->|%04.*x|<--\n", -2, 198));
// printf("%d\n", ft_printf("-->|%04.*x|<--\n", -2, 198));
// printf("%d\n", printf("-->|%04.*x|<--\n", -1, 198));
// printf("%d\n", ft_printf("-->|%04.*x|<--\n", -1, 198));
// printf("%d\n", printf("-->|%--4.x|<--\n", 198));
// printf("%d\n", ft_printf("-->|%--4.x|<--\n", 198));

// int		a = -4;
// printf("\n%d\n", printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
// printf("\n%d\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

// printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
// ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);


// printf("\n%d\n", printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0));
// printf("\n%d\n", ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0));

	int a = 8;
	while (a < 12) //
	{
		printf(" --- Return : %d\n",    printf("orign: %*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x",
				a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
		fflush(stdout);
		printf(" --- Return : %d\n", ft_printf("mypft: %*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x",
				a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
		printf(" --- Return : %d\n",    printf("orign: %-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x",
				a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
		fflush(stdout);
		printf(" --- Return : %d\n", ft_printf("mypft: %-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x",
				a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

		a++;
	}
	// printf("\n==========================================================\n");

	// a = 8;
	// while (a < 12) //
	// {
	// 	printf(" --- Return : %d\n", ft_printf("mypft: %*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x",
	// 			a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	printf(" --- Return : %d\n", ft_printf("mypft: %-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x",
	// 			a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	a++;
	// }
fflush(stdout);
// int a = 8;
// printf(" --- Return : %d\n",    printf("orign: %*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
// printf(" --- Return : %d\n", ft_printf("mypft: %*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));


// printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0);
// ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0);

// printf("%d\n", printf("-->|%04.*x|<--\n", 0, 198));
// printf("%d\n", ft_printf("-->|%04.*x|<--\n", 0, 198));
// printf("%d\n", printf("-->|%04.*x|<--\n", 1, 198));
// printf("%d\n", ft_printf("-->|%04.*x|<--\n", 1, 198));
// printf("%d\n", printf("-->|%04.*x|<--\n", 2, 198));
// printf("%d\n", ft_printf("-->|%04.*x|<--\n", 2, 198));

	// int iii = -5;
	// while(iii < 6)
	// {
	// 	printf("printf   : -->|%-1.d|<--\n", iii);
	// 	ft_printf("ft_printf: -->|%-1.d|<--\n", iii);
	// 	iii++;
	// }
}

