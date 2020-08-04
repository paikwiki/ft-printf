#include "test.h"

/*
    apply => .* ; * ; - ; 0 ; ' ' ; +
*/
void d()
{
    printf("====%%d TEST====\n");
    int a;
    int b;
    /*
    normal
    */
    //t1
    printf("\n===========\n");
    printf("t1 / fmt : %%d / num : 0\n");
    a = ft_printf("ft : %%%d%%\n", 0);
    b = printf("sr : %%%d%%\n", 0);
    printf("return %d %d\n", a, b);

    //t2
    printf("\n===========\n");
    printf("t2 / fmt : %%d / num : 555\n");
    a = ft_printf("ft : %%%d%%\n", 555);
    b = printf("sr : %%%d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t3
    printf("\n===========\n");
    printf("t3 / fmt : %%d / num : -15\n");
    a = ft_printf("ft : %%%d%%\n", -15);
    b = printf("sr : %%%d%%\n", -15);
    printf("return %d %d\n", a, b);

    /*
        * (width)
    */
    //t4
    printf("\n===========\n");
    printf("t4 fmt : %%2d / num : 555\n");
    a = ft_printf("ft : %%%2d%%\n", 555);
    b = printf("sr : %%%2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t5
    printf("\n===========\n");
    printf("t5 fmt : %%5d / num : 555\n");
    a = ft_printf("ft : %%%5d%%\n", 555);
    b = printf("sr : %%%5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t6
    printf("\n===========\n");
    printf("t6 fmt : %%*d / num : 10, 555\n");
    a = ft_printf("ft : %%%*d%%\n", 10, 555);
    b = printf("sr : %%%*d%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        .* (precision)
    */
    //t7
    printf("\n===========\n");
    printf("t7 fmt : %%.2d / num : 555\n");
    a = ft_printf("ft : %%%.2d%%\n", 555);
    b = printf("sr : %%%.2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t8
    printf("\n===========\n");
    printf("t8 fmt : %%.5d / num : 555\n");
    a = ft_printf("ft : %%%.5d%%\n", 555);
    b = printf("sr : %%%.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t9
    printf("\n===========\n");
    printf("t9 fmt : %%.*d / num : 10, 555\n");
    a = ft_printf("ft : %%%.*d%%\n", 10, 555);
    b = printf("sr : %%%.*d%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        - and * (width)
    */
    //t10
    printf("\n===========\n");
    printf("t10 fmt : %%-2d / num : 555\n");
    a = ft_printf("ft : %%%-2d%%\n", 555);
    b = printf("sr : %%%-2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t11
    printf("\n===========\n");
    printf("t11 fmt : %%-5d / num : 555\n");
    a = ft_printf("ft : %%%-5d%%\n", 555);
    b = printf("sr : %%%-5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t12
    printf("\n===========\n");
    printf("t10 fmt : %%-d / num : 555\n");
    a = ft_printf("ft : %%%-d%%\n", 555);
    b = printf("sr : %%%-d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t13
    printf("\n===========\n");
    printf("t13 fmt : %%-*d / num : 10, 555\n");
    a = ft_printf("ft : %%%-*d%%\n", 10, 555);
    b = printf("sr : %%%-*d%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        - .* (precision)
    */
    //t14
    printf("\n===========\n");
    printf("t14 fmt : %%-.2d / num : 555\n");
    a = ft_printf("ft : %%%-.2d%%\n", 555);
    b = printf("sr : %%%-.2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t15
    printf("\n===========\n");
    printf("t15 fmt : %%-.5d / num : 555\n");
    a = ft_printf("ft : %%%-.5d%%\n", 555);
    b = printf("sr : %%%-.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t16
    printf("\n===========\n");
    printf("t14 fmt : %%-.*d / num : 10, 555\n");
    a = ft_printf("ft : %%%-.*d%%\n", 10, 555);
    b = printf("sr : %%%-.*d%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        0 *
    */
    //t17
    printf("\n===========\n");
    printf("t17 fmt : %%0d / num : 555\n");
    a = ft_printf("ft : %%%0d%%\n", 555);
    b = printf("sr : %%%0d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t18
    printf("\n===========\n");
    printf("t18 fmt : %%02d / num : 555\n");
    a = ft_printf("ft : %%%02d%%\n", 555);
    b = printf("sr : %%%02d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t19
    printf("\n===========\n");
    printf("t19 fmt : %%05d / num : 555\n");
    a = ft_printf("ft : %%%05d%%\n", 555);
    b = printf("sr : %%%05d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t20
    printf("\n===========\n");
    printf("t20 fmt : %%0.5d / num : 555\n");
    a = ft_printf("ft : %%%0.5d%%\n", 555);
    b = printf("sr : %%%0.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t20
    printf("\n===========\n");
    printf("t20 fmt : %%0.*d / num : 555\n");
    a = ft_printf("ft : %%%0.*d%%\n", 2, 555);
    b = printf("sr : %%%0.*d%%\n", 2, 555);
    printf("return %d %d\n", a, b);
    
    //t21
    printf("\n===========\n");
    printf("t21 fmt : %%05d / num : 0\n");
    a = ft_printf("ft : %%%05d%%\n", 0);
    b = printf("sr : %%%05d%%\n", 0);
    printf("return %d %d\n", a, b);

    /*
        ' '
    */
    //t22
    printf("\n===========\n");
    printf("t22 fmt : %% d / num : 555\n");
    a = ft_printf("ft : %%% d%%\n", 555);
    b = printf("sr : %%% d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t23
    printf("\n===========\n");
    printf("t23 fmt : %% d / num : -555\n");
    a = ft_printf("ft : %%% d%%\n", -555);
    b = printf("sr : %%% d%%\n", -555);
    printf("return %d %d\n", a, b);

    //t24
    printf("\n===========\n");
    printf("t24 fmt : %% 5d / num : 555\n");
    a = ft_printf("ft : %%% 5d%%\n", 555);
    b = printf("sr : %%% 5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t25
    printf("\n===========\n");
    printf("t25 fmt : %% 5d / num : -555\n");
    a = ft_printf("ft : %%% 5d%%\n", -555);
    b = printf("sr : %%% 5d%%\n", -555);
    printf("return %d %d\n", a, b);

    //t26
    printf("\n===========\n");
    printf("t26 fmt : %% 2d / num : 555\n");
    a = ft_printf("ft : %%% 2d%%\n", 555);
    b = printf("sr : %%% 2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t27
    printf("\n===========\n");
    printf("t27 fmt : %% 2d / num : -555\n");
    a = ft_printf("ft : %%% 2d%%\n", -555);
    b = printf("sr : %%% 2d%%\n", -555);
    printf("return %d %d\n", a, b);

    //t28
    printf("\n===========\n");
    printf("t28 fmt : %% .2d / num : 555\n");
    a = ft_printf("ft : %%% .2d%%\n", 555);
    b = printf("sr : %%% .2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t29
    printf("\n===========\n");
    printf("t29 fmt : %% .5d / num : 555\n");
    a = ft_printf("ft : %%% .5d%%\n", 555);
    b = printf("sr : %%% .5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t30
    printf("\n===========\n");
    printf("t31 fmt : %% .5d / num : -555\n");
    a = ft_printf("ft : %%% .5d%%\n", -555);
    b = printf("sr : %%% .5d%%\n", -555);
    printf("return %d %d\n", a, b);

    /*
        +
    */
    //t31
    printf("\n===========\n");
    printf("t31 fmt : %%+d / num : 555\n");
    a = ft_printf("ft : %%%+d%%\n", 555);
    b = printf("sr : %%%+d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t32
    printf("\n===========\n");
    printf("t32 fmt : %%+d / num : 0\n");
    a = ft_printf("ft : %%%+d%%\n", 0);
    b = printf("sr : %%%+d%%\n", 0);
    printf("return %d %d\n", a, b);

    //t33
    printf("\n===========\n");
    printf("t33 fmt : %%+d / num : -5\n");
    a = ft_printf("ft : %%%+d%%\n", -5);
    b = printf("sr : %%%+d%%\n", -5);
    printf("return %d %d\n", a, b);

    //t34
    printf("\n===========\n");
    printf("t34 fmt : %% +d / num : 555\n");
    a = ft_printf("ft : %%% +d%%\n", 555);
    b = printf("sr : %%% +d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t35
    printf("\n===========\n");
    printf("t35 fmt : %%+2d / num : 555\n");
    a = ft_printf("ft : %%%+2d%%\n", 555);
    b = printf("sr : %%%+2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t36
    printf("\n===========\n");
    printf("t36 fmt : %%+5d / num : 555\n");
    a = ft_printf("ft : %%%+5d%%\n", 555);
    b = printf("sr : %%%+5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t37
    printf("\n===========\n");
    printf("t37 fmt : %%+.2d / num : 555\n");
    a = ft_printf("ft : %%%+.2d%%\n", 555);
    b = printf("sr : %%%+.2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t38
    printf("\n===========\n");
    printf("t38 fmt : %%+.5d / num : 555\n");
    a = ft_printf("ft : %%%+.5d%%\n", 555);
    b = printf("sr : %%%+.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t39
    printf("\n===========\n");
    printf("t39 fmt : %%.5d / num : 555\n");
    a = ft_printf("ft : %%%+.5d%%\n", 555);
    b = printf("sr : %%%+.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    /*
        * .*
    */
    //t40
    printf("\n===========\n");
    printf("t40 fmt : %%10.5d / num : 555\n");
    a = ft_printf("ft : %%%10.5d%%\n", 555);
    b = printf("sr : %%%10.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t41
    printf("\n===========\n");
    printf("t41 fmt : %%2.5d / num : 555\n");
    a = ft_printf("ft : %%%2.5d%%\n", 555);
    b = printf("sr : %%%2.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t42
    printf("\n===========\n");
    printf("t42 fmt : %%5.2d / num : 555\n");
    a = ft_printf("ft : %%%5.2d%%\n", 555);
    b = printf("sr : %%%5.2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t43
    printf("\n===========\n");
    printf("t43 fmt : %%5.5d / num : 555\n");
    a = ft_printf("ft : %%%5.5d%%\n", 555);
    b = printf("sr : %%%5.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    /*
        comb anything
    */
    //t44
    printf("\n===========\n");
    printf("t44 fmt : %% 2.2d / num : 555\n");
    a = ft_printf("ft : %%% 2.2d%%\n", 555);
    b = printf("sr : %%% 2.2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t45
    printf("\n===========\n");
    printf("t45 fmt : %% -5.2d / num : 555\n");
    a = ft_printf("ft : %%% -5.2d%%\n", 555);
    b = printf("sr : %%% -5.2d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t46
    printf("\n===========\n");
    printf("t46 fmt : %%+-10.5d / num : -555\n");
    a = ft_printf("ft : %%%+-10.5d%%\n", -555);
    b = printf("sr : %%%+-10.5d%%\n", -555);
    printf("return %d %d\n", a, b);

    //t47
    printf("\n===========\n");
    printf("t47 fmt : %%07.5d / num : 555\n");
    a = ft_printf("ft : %%%07.5d%%\n", 555);
    b = printf("sr : %%%07.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t48
    printf("\n===========\n");
    printf("t48 fmt : %% 0.5d / num : 555\n");
    a = ft_printf("ft : %%% 0.5d%%\n", 555);
    b = printf("sr : %%% 0.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t49
    printf("\n===========\n");
    printf("t49 fmt : %% -.5d / num : 555\n");
    a = ft_printf("ft : %%% -.5d%%\n", 555);
    b = printf("sr : %%% -.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t50
    printf("\n===========\n");
    printf("t50 fmt : %%+2.5d / num : 555\n");
    a = ft_printf("ft : %%%+2.5d%%\n", 555);
    b = printf("sr : %%%+2.5d%%\n", 555);
    printf("return %d %d\n", a, b);

    //t51
    printf("\n===========\n");
    printf("t51 fmt : %%+2.5d / num : 0\n");
    a = ft_printf("ft : %%%+2.5d%%\n", 0);
    b = printf("sr : %%%+2.5d%%\n", 0);
    printf("return %d %d\n", a, b);

    //t52
    printf("\n===========\n");
    printf("t52 fmt : %%+++++--   2.5d / num : 0\n");
    a = ft_printf("ft : %%%+++++--   2.5d%%\n", 0);
    b = printf("sr : %%%+++++--   2.5d%%\n", 0);
    printf("return %d %d\n", a, b);

    //t53
    printf("\n===========\n");
    printf("t53 fmt : %%0-*.*d / num : 6, 2, 0\n");
    a = ft_printf("ft : %%%0-*.*d%%\n", 6, 2, 0);
    b = printf("sr : %%%0-*.*d%%\n", 6, 2, 0);
    printf("return %d %d\n", a, b);

    //t54
    printf("\n===========\n");
    printf("t54 fmt : %%000010d / num : 555\n");
    a = ft_printf("ft : %%%000010d%%\n", 555);
    b = printf("sr : %%%000010d%%\n", 555);
    printf("return %d %d\n", a, b);

}
