#include "test.h"


void x()
{
    printf("====%%x TEST====\n");
    int a;
    int b;
    /*
    normal
    */
    //t1
    printf("\n===========\n");
    printf("t1 / fmt : %%x / num : 0\n");
    a = ft_printf("ft : %%%x%%\n", 0);
    b = printf("sr : %%%x%%\n", 0);
    printf("return %d %d\n", a, b);

    //t2
    printf("\n===========\n");
    printf("t2 / fmt : %%x / num : 555\n");
    a = ft_printf("ft : %%%x%%\n", 555);
    b = printf("sr : %%%x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t3
    printf("\n===========\n");
    printf("t3 / fmt : %%x / num : -15\n");
    a = ft_printf("ft : %%%x%%\n", -15);
    b = printf("sr : %%%x%%\n", -15);
    printf("return %d %d\n", a, b);

    /*
        * (width)
    */
    //t4
    printf("\n===========\n");
    printf("t4 fmt : %%2x / num : 555\n");
    a = ft_printf("ft : %%%2x%%\n", 555);
    b = printf("sr : %%%2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t5
    printf("\n===========\n");
    printf("t5 fmt : %%5x / num : 555\n");
    a = ft_printf("ft : %%%5x%%\n", 555);
    b = printf("sr : %%%5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t6
    printf("\n===========\n");
    printf("t6 fmt : %%*x / num : 10, 555\n");
    a = ft_printf("ft : %%%*x%%\n", 10, 555);
    b = printf("sr : %%%*x%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        .* (precision)
    */
    //t7
    printf("\n===========\n");
    printf("t7 fmt : %%.2x / num : 555\n");
    a = ft_printf("ft : %%%.2x%%\n", 555);
    b = printf("sr : %%%.2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t8
    printf("\n===========\n");
    printf("t8 fmt : %%.5x / num : 555\n");
    a = ft_printf("ft : %%%.5x%%\n", 555);
    b = printf("sr : %%%.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t9
    printf("\n===========\n");
    printf("t9 fmt : %%.*x / num : 10, 555\n");
    a = ft_printf("ft : %%%.*x%%\n", 10, 555);
    b = printf("sr : %%%.*x%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        - and * (width)
    */
    //t10
    printf("\n===========\n");
    printf("t10 fmt : %%-2x / num : 555\n");
    a = ft_printf("ft : %%%-2x%%\n", 555);
    b = printf("sr : %%%-2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t11
    printf("\n===========\n");
    printf("t11 fmt : %%-5x / num : 555\n");
    a = ft_printf("ft : %%%-5x%%\n", 555);
    b = printf("sr : %%%-5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t12
    printf("\n===========\n");
    printf("t10 fmt : %%-x / num : 555\n");
    a = ft_printf("ft : %%%-x%%\n", 555);
    b = printf("sr : %%%-x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t13
    printf("\n===========\n");
    printf("t13 fmt : %%-*x / num : 10, 555\n");
    a = ft_printf("ft : %%%-*x%%\n", 10, 555);
    b = printf("sr : %%%-*x%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        - .* (precision)
    */
    //t14
    printf("\n===========\n");
    printf("t14 fmt : %%-.2x / num : 555\n");
    a = ft_printf("ft : %%%-.2x%%\n", 555);
    b = printf("sr : %%%-.2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t15
    printf("\n===========\n");
    printf("t15 fmt : %%-.5x / num : 555\n");
    a = ft_printf("ft : %%%-.5x%%\n", 555);
    b = printf("sr : %%%-.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t16
    printf("\n===========\n");
    printf("t14 fmt : %%-.*x / num : 10, 555\n");
    a = ft_printf("ft : %%%-.*x%%\n", 10, 555);
    b = printf("sr : %%%-.*x%%\n", 10, 555);
    printf("return %d %d\n", a, b);

    /*
        0 *
    */
    //t17
    printf("\n===========\n");
    printf("t17 fmt : %%0x / num : 555\n");
    a = ft_printf("ft : %%%0x%%\n", 555);
    b = printf("sr : %%%0x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t18
    printf("\n===========\n");
    printf("t18 fmt : %%0xx / num : 555\n");
    a = ft_printf("ft : %%%02x%%\n", 555);
    b = printf("sr : %%%02u%%\n", 555);
    printf("return %d %d\n", a, b);

    //t19
    printf("\n===========\n");
    printf("t19 fmt : %%05x / num : 555\n");
    a = ft_printf("ft : %%%05x%%\n", 555);
    b = printf("sr : %%%05x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t20
    printf("\n===========\n");
    printf("t20 fmt : %%0.5x / num : 555\n");
    a = ft_printf("ft : %%%0.5x%%\n", 555);
    b = printf("sr : %%%0.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t20
    printf("\n===========\n");
    printf("t20 fmt : %%0.*x / num : 555\n");
    a = ft_printf("ft : %%%0.*x%%\n", 2, 555);
    b = printf("sr : %%%0.*x%%\n", 2, 555);
    printf("return %d %d\n", a, b);
    
    //t21
    printf("\n===========\n");
    printf("t21 fmt : %%05x / num : 0\n");
    a = ft_printf("ft : %%%05x%%\n", 0);
    b = printf("sr : %%%05x%%\n", 0);
    printf("return %d %d\n", a, b);

    /*
        ' '
    */
    //t22
    printf("\n===========\n");
    printf("t22 fmt : %% x / num : 555\n");
    a = ft_printf("ft : %%% x%%\n", 555);
    b = printf("sr : %%% x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t23
    printf("\n===========\n");
    printf("t23 fmt : %% x / num : -555\n");
    a = ft_printf("ft : %%% x%%\n", -555);
    b = printf("sr : %%% x%%\n", -555);
    printf("return %d %d\n", a, b);

    //t24
    printf("\n===========\n");
    printf("t24 fmt : %% 5x / num : 555\n");
    a = ft_printf("ft : %%% 5x%%\n", 555);
    b = printf("sr : %%% 5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t25
    printf("\n===========\n");
    printf("t25 fmt : %% 5x / num : -555\n");
    a = ft_printf("ft : %%% 5x%%\n", -555);
    b = printf("sr : %%% 5x%%\n", -555);
    printf("return %d %d\n", a, b);

    //t26
    printf("\n===========\n");
    printf("t26 fmt : %% 2x / num : 555\n");
    a = ft_printf("ft : %%% 2x%%\n", 555);
    b = printf("sr : %%% 2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t27
    printf("\n===========\n");
    printf("t27 fmt : %% 2x / num : -555\n");
    a = ft_printf("ft : %%% 2x%%\n", -555);
    b = printf("sr : %%% 2x%%\n", -555);
    printf("return %d %d\n", a, b);

    //t28
    printf("\n===========\n");
    printf("t28 fmt : %% .2x / num : 555\n");
    a = ft_printf("ft : %%% .2x%%\n", 555);
    b = printf("sr : %%% .2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t29
    printf("\n===========\n");
    printf("t29 fmt : %% .5x / num : 555\n");
    a = ft_printf("ft : %%% .5x%%\n", 555);
    b = printf("sr : %%% .5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t30
    printf("\n===========\n");
    printf("t31 fmt : %% .5x / num : -555\n");
    a = ft_printf("ft : %%% .5x%%\n", -555);
    b = printf("sr : %%% .5x%%\n", -555);
    printf("return %d %d\n", a, b);

    /*
        +
    */
    //t31
    printf("\n===========\n");
    printf("t31 fmt : %%+x / num : 555\n");
    a = ft_printf("ft : %%%+x%%\n", 555);
    b = printf("sr : %%%+x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t32
    printf("\n===========\n");
    printf("t32 fmt : %%+x / num : 0\n");
    a = ft_printf("ft : %%%+x%%\n", 0);
    b = printf("sr : %%%+x%%\n", 0);
    printf("return %d %d\n", a, b);

    //t33
    printf("\n===========\n");
    printf("t33 fmt : %%+x / num : -5\n");
    a = ft_printf("ft : %%%+x%%\n", -5);
    b = printf("sr : %%%+x%%\n", -5);
    printf("return %d %d\n", a, b);

    //t34
    printf("\n===========\n");
    printf("t34 fmt : %% +x / num : 555\n");
    a = ft_printf("ft : %%% +x%%\n", 555);
    b = printf("sr : %%% +x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t35
    printf("\n===========\n");
    printf("t35 fmt : %%+2x / num : 555\n");
    a = ft_printf("ft : %%%+2x%%\n", 555);
    b = printf("sr : %%%+2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t36
    printf("\n===========\n");
    printf("t36 fmt : %%+5x / num : 555\n");
    a = ft_printf("ft : %%%+5x%%\n", 555);
    b = printf("sr : %%%+5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t37
    printf("\n===========\n");
    printf("t37 fmt : %%+.2x / num : 555\n");
    a = ft_printf("ft : %%%+.2x%%\n", 555);
    b = printf("sr : %%%+.2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t38
    printf("\n===========\n");
    printf("t38 fmt : %%+.5x / num : 555\n");
    a = ft_printf("ft : %%%+.5x%%\n", 555);
    b = printf("sr : %%%+.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t39
    printf("\n===========\n");
    printf("t39 fmt : %%.5x / num : 555\n");
    a = ft_printf("ft : %%%+.5x%%\n", 555);
    b = printf("sr : %%%+.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    /*
        * .*
    */
    //t40
    printf("\n===========\n");
    printf("t40 fmt : %%10.5x / num : 555\n");
    a = ft_printf("ft : %%%10.5x%%\n", 555);
    b = printf("sr : %%%10.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t41
    printf("\n===========\n");
    printf("t41 fmt : %%2.5x / num : 555\n");
    a = ft_printf("ft : %%%2.5x%%\n", 555);
    b = printf("sr : %%%2.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t42
    printf("\n===========\n");
    printf("t42 fmt : %%5.2x / num : 555\n");
    a = ft_printf("ft : %%%5.2x%%\n", 555);
    b = printf("sr : %%%5.2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t43
    printf("\n===========\n");
    printf("t43 fmt : %%5.5x / num : 555\n");
    a = ft_printf("ft : %%%5.5x%%\n", 555);
    b = printf("sr : %%%5.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    /*
        comb anything
    */
    //t44
    printf("\n===========\n");
    printf("t44 fmt : %% 2.2x / num : 555\n");
    a = ft_printf("ft : %%% 2.2x%%\n", 555);
    b = printf("sr : %%% 2.2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t45
    printf("\n===========\n");
    printf("t45 fmt : %% -5.2x / num : 555\n");
    a = ft_printf("ft : %%% -5.2x%%\n", 555);
    b = printf("sr : %%% -5.2x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t46
    printf("\n===========\n");
    printf("t46 fmt : %%+-10.5x / num : -555\n");
    a = ft_printf("ft : %%%+-10.5x%%\n", -555);
    b = printf("sr : %%%+-10.5x%%\n", -555);
    printf("return %d %d\n", a, b);

    //t47
    printf("\n===========\n");
    printf("t47 fmt : %%07.5x / num : 555\n");
    a = ft_printf("ft : %%%07.5x%%\n", 555);
    b = printf("sr : %%%07.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t48
    printf("\n===========\n");
    printf("t48 fmt : %% 0.5x / num : 555\n");
    a = ft_printf("ft : %%% 0.5x%%\n", 555);
    b = printf("sr : %%% 0.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t49
    printf("\n===========\n");
    printf("t49 fmt : %% -.5x / num : 555\n");
    a = ft_printf("ft : %%% -.5x%%\n", 555);
    b = printf("sr : %%% -.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t50
    printf("\n===========\n");
    printf("t50 fmt : %%+2.5x / num : 555\n");
    a = ft_printf("ft : %%%+2.5x%%\n", 555);
    b = printf("sr : %%%+2.5x%%\n", 555);
    printf("return %d %d\n", a, b);

    //t51
    printf("\n===========\n");
    printf("t51 fmt : %%+2.5x / num : 0\n");
    a = ft_printf("ft : %%%+2.5x%%\n", 0);
    b = printf("sr : %%%+2.5x%%\n", 0);
    printf("return %d %d\n", a, b);

    //t52
    printf("\n===========\n");
    printf("t52 fmt : %%+++++--   2.5x / num : 0\n");
    a = ft_printf("ft : %%%+++++--   2.5x%%\n", 0);
    b = printf("sr : %%%+++++--   2.5x%%\n", 0);
    printf("return %d %d\n", a, b);

    //t53
    printf("\n===========\n");
    printf("t53 fmt : %%0-*.*x / num : 6, 2, 0\n");
    a = ft_printf("ft : %%%0-*.*x%%\n", 6, 2, 0);
    b = printf("sr : %%%0-*.*x%%\n", 6, 2, 0);
    printf("return %d %d\n", a, b);

    //t54
    printf("\n===========\n");
    printf("t54 fmt : %%000010x / num : 555\n");
    a = ft_printf("ft : %%%000010x%%\n", 555);
    b = printf("sr : %%%000010x%%\n", 555);
    printf("return %d %d\n", a, b);

    
    //t55
    printf("\n===========\n");
    printf("t55 fmt : %%x / num : -1\n");
    a = ft_printf("ft : %%%x%%\n", -1);
    b = printf("sr : %%%x%%\n", -1);
    printf("return %d %d\n", a, b);

    //t56
    printf("\n===========\n");
    printf("t56 fmt : %%x / num : 2147483648\n");
    a = ft_printf("ft : %%%x%%\n", 2147483648);
    b = printf("sr : %%%x%%\n", 2147483648);
    printf("return %d %d\n", a, b);

    //t57
    printf("\n===========\n");
    printf("t57 fmt : %%x / num : 4294967296\n");
    a = ft_printf("ft : %%%x%%\n", 4294967296);
    b = printf("sr : %%%x%%\n", 4294967296);
    printf("return %d %d\n", a, b);

    //t58
    printf("\n===========\n");
    printf("t58 fmt : %%#x / num : 25\n");
    a = ft_printf("ft : %%%#x%%\n", 25);
    b = printf("sr : %%%#x%%\n", 25);
    printf("return %d %d\n", a, b);

    //t59
    printf("\n===========\n");
    printf("t59 fmt : %%+0#5x / num : 25\n");
    a = ft_printf("ft : %%%+0#5x%%\n", 25);
    b = printf("sr : %%%+0#5x%%\n", 25);
    printf("return %d %d\n", a, b);

    //t60
    printf("\n===========\n");
    printf("t60 fmt : %% 0#5x / num : 25\n");
    a = ft_printf("ft : %%% 0#5x%%\n", 25);
    b = printf("sr : %%% 0#5x%%\n", 25);
    printf("return %d %d\n", a, b);

    //t61
    printf("\n===========\n");
    printf("t61 fmt : %% 0#5x / num : 25\n");
    a = ft_printf("ft : %%% 0#10x%%\n", 25);
    b = printf("sr : %%% 0#10x%%\n", 25);
    printf("return %d %d\n", a, b);

    //t62
    printf("\n===========\n");
    printf("t62 fmt : %% #10.5x / num : 25\n");
    a = ft_printf("ft : %%% #10.5x%%\n", 25);
    b = printf("sr : %%% #10.5x%%\n", 25);
    printf("return %d %d\n", a, b);

    //t63
    printf("\n===========\n");
    printf("t63 fmt : %% #.5x / num : 25\n");
    a = ft_printf("ft : %%% #.5x%%\n", 25);
    b = printf("sr : %%% #.5x%%\n", 25);
    printf("return %d %d\n", a, b);

    //t64
    printf("\n===========\n");
    printf("t64 fmt : %%-#.5x / num : 25\n");
    a = ft_printf("ft : %%%-#.5x%%\n", 25);
    b = printf("sr : %%%-#.5x%%\n", 25);
    printf("return %d %d\n", a, b);

    //t65
    printf("\n===========\n");
    printf("t65 fmt : %%-#10X / num : 30\n");
    a = ft_printf("ft : %%%-#10X%%\n", 30);
    b = printf("sr : %%%-#10X%%\n", 30);
    printf("return %d %d\n", a, b);
}