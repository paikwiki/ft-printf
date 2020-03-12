#include "libft.h"
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>
int main()
{
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t msg[] = L"안녕하세요.";
	printf("%d\n", printf("%lc\n", msg[0]));
	printf("%d\n", printf("%ls 끝.\n", msg));
	ft_printf("%d\n", ft_printf("%lc\n", msg[0]));
	ft_printf("%d\n", ft_printf("%ls 끝.\n", msg));
}
