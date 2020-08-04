#include <stdio.h>

int main(void)
{
	ft_printf("%s, %s!\n", "Hello", "world");
	ft_printf("%+++09.5d\n", 100);		//   +00100
	ft_printf("%+09d\n", 100);		//+00000100
	ft_printf("%+9.5d\n", 100);		//   +00100
	ft_printf("%+9.*d\n", 5, 100);		//   +00100
	ft_printf("%s, %s!\n", "Hello", "world");
	ft_printf("%0d\n", 100);		//100
	ft_printf("%0 9d\n", 100);		// 00000100
	printf("%s, %s!\n", "Hello", "world");
	printf("%0d\n", 100);		//100
	printf("%0 9d\n", 100);		// 00000100
	ft_printf("%09.5d\n", 100);		//    00100
	ft_printf("%09d\n", 100);		//000000100
	ft_printf("%9.5d\n", 100);		//    00100
	ft_printf("%9.*d\n", 5, 100);		//    00100
	ft_printf("%09.5d\n", -100);		//   -00100
	ft_printf("%09d\n", -100);		//-00000100
	ft_printf("%9.5d\n", -100);		//   -00100
	ft_printf("%9.*d\n", 5, -100);		//   -00100
	printf("===\n");
	ft_printf("%*.*d\n", 9,  5, -100);	//   -00100
	printf("%*.*d\n", 9,  5, -100);		//   -00100
	printf("===\n");
	ft_printf("%*.*d\n", 5,  5, -100);	//   -00100
	printf("%*.*d\n", 5,  5, -100);		//   -00100
	printf("===\n");
	ft_printf("%d\n" , ft_printf("%*.*ld", 0, 0, -9223372036854775807 - 1));
	printf("%d\n", printf("%*.*ld", 0,  0, -9223372036854775807 - 1));
	printf("===\n");
	ft_printf("return = %d\n", ft_printf("%%d%   d\n", 0));	//%d 0
	printf("return = %d\n", printf("%%d%   d\n", 0));	//%d 0
	ft_printf("return = %d\n", ft_printf("%%d%-d\n", 0));	//%d0
	printf("return = %d\n", printf("%%d%-d\n", 0));		//%d0
	ft_printf("return = %d\n", ft_printf("%%d%+d\n", 0));	//%d+0
	printf("return = %d\n", printf("%%d%+d\n", 0));		//%d+0
	printf("%d\n",printf("%d %c\n", 50, -1));
	ft_printf("%d\n",printf("%d %c\n", 50, 128));
	printf("%d\n",printf("%c %d\n", 128, 50));
	ft_printf("%d\n",printf("%c %d\n", 128, 50));
	printf("%d\n", printf("%d %lc\n", 50, 128));
	ft_printf("%d\n",ft_printf("%d %lc\n", 50, 128));
	return (0);
}
