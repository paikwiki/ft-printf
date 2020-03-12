#include "test.h"

/*
    ' ' - 0 .* * +
*/
void p()
{
    printf("=======p TEST=====\n");
    //t1
    void *c = malloc(sizeof(char));
    printf("\n===========\n");
    printf("t1 fmt : %%p / num : 30\n");
    int a = ft_printf("ft : %%%p%%\n", 30);
    int b = printf("sr : %%%p%%\n", 30);
    printf("return %d %d\n", a, b);

    //t2
    printf("\n===========\n");
    printf("t2 fmt : %%p / num : something\n");
    a = ft_printf("ft : %%%p%%\n", c);
    b = printf("sr : %%%p%%\n", c);
    printf("return %d %d\n", a, b);

    //t3
    printf("\n===========\n");
    printf("t3 fmt : %% p / num : something\n");
    a = ft_printf("ft : %%% p%%\n", c);
    b = printf("sr : %%% p%%\n", c);
    printf("return %d %d\n", a, b);

    //t4
    printf("\n===========\n");
    printf("t4 fmt : %%10p / num : 30\n");
    a = ft_printf("ft : %%%10p%%\n", 30);
    b = printf("sr : %%%10p%%\n", 30);
    printf("return %d %d\n", a, b);

    //t5
    printf("\n===========\n");
    printf("t5 fmt : %%.7p / num : 30\n");
    a = ft_printf("ft : %%%.7p%%\n", 30);
    b = printf("sr : %%%.7p%%\n", 30);
    printf("return %d %d\n", a, b);

    //t6
    printf("\n===========\n");
    printf("t6 fmt : %%30.20p / num : something\n");
    a = ft_printf("ft : %%%30.20p%%\n", c);
    b = printf("sr : %%%30.20p%%\n", c);
    printf("return %d %d\n", a, b);

    //t7
    printf("\n===========\n");
    printf("t7 fmt : %% -30.20p / num : something\n");
    a = ft_printf("ft : %%% -30.20p%%\n", c);
    b = printf("sr : %%% -30.20p%%\n", c);
    printf("return %d %d\n", a, b);

    //t8
    printf("\n===========\n");
    printf("t8 fmt : %%+#030.20p / num : something\n");
    a = ft_printf("ft : %%%+#030.20p%%\n", c);
    b = printf("sr : %%%+#030.20p%%\n", c);
    printf("return %d %d\n", a, b);

    //t9
    printf("\n===========\n");
    printf("t9 fmt : %%+#030p / num : something\n");
    a = ft_printf("ft : %%%+#030p%%\n", c);
    b = printf("sr : %%%+#030p%%\n", c);
    printf("return %d %d\n", a, b);

    //t11
    printf("\n===========\n");
    printf("t11 fmt : %%+#40.30p / num : something\n");
    a = ft_printf("ft : %%%+#40.30p%%\n", c);
    b = printf("sr : %%%+#40.30p%%\n", c);
    printf("return %d %d\n", a, b);
}