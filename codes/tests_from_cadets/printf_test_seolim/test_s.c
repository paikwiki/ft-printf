#include "test.h"

void s()
{
    printf("====%%s TEST====\n");
    int a;
    int b;
    /*
    normal
    */
    //t1
    printf("\n===========\n");
    printf("t1 / fmt : %%s / str : 1234\n");
    a = ft_printf("ft : %%%s%%\n", "1234");
    b = printf("sr : %%%s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t2
    printf("\n===========\n");
    printf("t2 / fmt : %%2s / str : 1234\n");
    a = ft_printf("ft : %%%2s%%\n", "1234");
    b = printf("sr : %%%2s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t3
    printf("\n===========\n");
    printf("t3 / fmt : %%5s / str : 1234\n");
    a = ft_printf("ft : %%%5s%%\n", "1234");
    b = printf("sr : %%%5s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t4
    printf("\n===========\n");
    printf("t4 / fmt : %%.3s / str : 1234\n");
    a = ft_printf("ft : %%%.3s%%\n", "1234");
    b = printf("sr : %%%.3s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t5
    printf("\n===========\n");
    printf("t5 / fmt : %%.6s / str : 1234\n");
    a = ft_printf("ft : %%%.6s%%\n", "1234");
    b = printf("sr : %%%.6s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t6
    printf("\n===========\n");
    printf("t6 / fmt : %%5.6s / str : 1234\n");
    a = ft_printf("ft : %%%5.6s%%\n", "1234");
    b = printf("sr : %%%5.6s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t7
    printf("\n===========\n");
    printf("t7 / fmt : %%5.2s / str : 1234\n");
    a = ft_printf("ft : %%%5.2s%%\n", "1234");
    b = printf("sr : %%%5.2s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t8
    printf("\n===========\n");
    printf("t8 / fmt : %%2.5s / str : 1234\n");
    a = ft_printf("ft : %%%2.5s%%\n", "1234");
    b = printf("sr : %%%2.5s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t9
    printf("\n===========\n");
    printf("t9 / fmt : %%-6s / str : 1234\n");
    a = ft_printf("ft : %%%-6s%%\n", "1234");
    b = printf("sr : %%%-6s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t10
    printf("\n===========\n");
    printf("t10 / fmt : %%-6.2s / str : 1234\n");
    a = ft_printf("ft : %%%-6.2s%%\n", "1234");
    b = printf("sr : %%%-6.2s%%\n", "1234");
    printf("return %d %d\n", a, b);

    //t11
    printf("\n===========\n");
    printf("t11 / fmt : %%s / str : ""\n");
    a = ft_printf("ft : %%%s%%\n", "");
    b = printf("sr : %%%s%%\n", "");
    printf("return %d %d\n", a, b);

    //t12
    printf("\n===========\n");
    printf("t12 / fmt : %%10s / str : ""\n");
    a = ft_printf("ft : %%%10s%%\n", "");
    b = printf("sr : %%%10s%%\n", "");
    printf("return %d %d\n", a, b);

    //t13
    printf("\n===========\n");
    printf("t13 / fmt : %%s / str : 0(null)\n");
    a = ft_printf("ft : %%%s%%\n", 0);
    b = printf("sr : %%%s%%\n", 0);
    printf("return %d %d\n", a, b);

    //t14
    printf("\n===========\n");
    printf("t14 / fmt : %%10s / num : 0(null)\n");
    a = ft_printf("ft : %%%10s%%\n", 0);
    b = printf("sr : %%%10s%%\n", 0);
    printf("return %d %d\n", a, b);

    //t15
    printf("\n===========\n");
    printf("t15 / fmt : %%.5s / num : 0(null)\n");
    a = ft_printf("ft : %%%.5s%%\n", 0);
    b = printf("sr : %%%.5s%%\n", 0);
    printf("return %d %d\n", a, b);

    //t16
    printf("\n===========\n");
    printf("t16 / fmt : %%.6s / num : 0(null)\n");
    a = ft_printf("ft : %%%.6s%%\n", 0);
    b = printf("sr : %%%.6s%%\n", 0);
    printf("return %d %d\n", a, b);

    //t17
    printf("\n===========\n");
    printf("t17 / fmt : %%10.5s / num : 0(null)\n");
    a = ft_printf("ft : %%%10.5s%%\n", 0);
    b = printf("sr : %%%10.5s%%\n", 0);
    printf("return %d %d\n", a, b);

    //t18
    printf("\n===========\n");
    printf("t18 / fmt : %%-10s / num : 0(null)\n");
    a = ft_printf("ft : %%%-10s%%\n", 0);
    b = printf("sr : %%%-10s%%\n", 0);
    printf("return %d %d\n", a, b);
}
