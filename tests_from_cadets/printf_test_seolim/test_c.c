#include "test.h"

/*
    apply => * - 
*/

void c()
{
    int a;
    int b;

    printf("====%%c TEST====\n");
    //t1
    printf("\n===========\n");
    printf("t1 / fmt : %%c / char : a\n");
    a = ft_printf("ft : %%%c%%\n", 'a');
    b = printf("sr : %%%c%%\n", 'a');
    printf("return %d %d\n", a, b);

    //t2
    printf("\n===========\n");
    printf("t2 / fmt : %%5c / char : a\n");
    a = ft_printf("ft : %%%5c%%\n", 'a');
    b = printf("sr : %%%5c%%\n", 'a');
    printf("return %d %d\n", a, b);

    //t3
    printf("\n===========\n");
    printf("t3 / fmt : %%-5c / char : a\n");
    a = ft_printf("ft : %%%-5c%%\n", 'a');
    b = printf("sr : %%%-5c%%\n", 'a');
    printf("return %d %d\n", a, b);

    //t4
    printf("\n===========\n");
    printf("t4 / fmt : %%-.5c / char : a\n");
    a = ft_printf("ft : %%%-.5c%%\n", 'a');
    b = printf("sr : %%%-.5c%%\n", 'a');
    printf("return %d %d\n", a, b);

    //t5
    printf("\n===========\n");
    printf("t5 / fmt : %%5.5c / char : a\n");
    a = ft_printf("ft : %%%5.5c%%\n", 'a');
    b = printf("sr : %%%5.5c%%\n", 'a');
    printf("return %d %d\n", a, b);

    //t6
    printf("\n===========\n");
    printf("t6 / fmt : %% c / char : a\n");
    a = ft_printf("ft : %%% c%%\n", 'a');
    b = printf("sr : %%% c%%\n", 'a');
    printf("return %d %d\n", a, b);

    //t7
    printf("\n===========\n");
    printf("t7 / fmt : %%0c / char : a\n");
    a = ft_printf("ft : %%%0c%%\n", 'a');
    b = printf("sr : %%%0c%%\n", 'a');
    printf("return %d %d\n", a, b);

    //t8
    printf("\n===========\n");
    printf("t8 / fmt : %%1c / char : a\n");
    a = ft_printf("ft : %%%1c%%\n", 'a');
    b = printf("sr : %%%1c%%\n", 'a');
    printf("return %d %d\n", a, b);
}