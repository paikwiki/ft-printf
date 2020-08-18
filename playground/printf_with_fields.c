#include <stdio.h>

int main(void)
{
	printf("$%1d$\t%%1d\n", 1234);
	printf("$%2d$\t%%2d\n", 1234);
	printf("$%3d$\t%%3d\n", 1234);
	printf("$%4d$\t%%4d\n", 1234);
	printf("$%5d$\t%%5d\n", 1234);
	printf("$%6d$\t%%6d\n", 1234);
	printf("$%7d$\t%%7d\n", 1234);
	printf("$%8d$\t%%8d\n", 1234);

	printf("==================\n");

	printf("$%-1d$\t%%-1d\n", 1234);
	printf("$%-2d$\t%%-2d\n", 1234);
	printf("$%-3d$\t%%-3d\n", 1234);
	printf("$%-4d$\t%%-4d\n", 1234);
	printf("$%-5d$\t%%-5d\n", 1234);
	printf("$%-6d$\t%%-6d\n", 1234);
	printf("$%-7d$\t%%-7d\n", 1234);
	printf("$%-8d$\t%%-8d\n", 1234);

	printf("==================\n");

	printf("$%01d$\t%%01d\n", 1234);
	printf("$%02d$\t%%02d\n", 1234);
	printf("$%03d$\t%%03d\n", 1234);
	printf("$%04d$\t%%04d\n", 1234);
	printf("$%05d$\t%%05d\n", 1234);
	printf("$%06d$\t%%06d\n", 1234);
	printf("$%07d$\t%%07d\n", 1234);
	printf("$%08d$\t%%08d\n", 1234);

	printf("==================\n");

	printf("$%.1d$\t%%.1d\n", 1234);
	printf("$%.2d$\t%%.2d\n", 1234);
	printf("$%.3d$\t%%.3d\n", 1234);
	printf("$%.4d$\t%%.4d\n", 1234);
	printf("$%.5d$\t%%.5d\n", 1234);
	printf("$%.6d$\t%%.6d\n", 1234);
	printf("$%.7d$\t%%.7d\n", 1234);
	printf("$%.8d$\t%%.8d\n", 1234);

	printf("==================\n");

	printf("$%8.1d$\t%%8.1d\n", 1234);
	printf("$%8.2d$\t%%8.2d\n", 1234);
	printf("$%8.3d$\t%%8.3d\n", 1234);
	printf("$%8.4d$\t%%8.4d\n", 1234);
	printf("$%8.5d$\t%%8.5d\n", 1234);
	printf("$%8.6d$\t%%8.6d\n", 1234);
	printf("$%8.7d$\t%%8.7d\n", 1234);
	printf("$%8.8d$\t%%8.8d\n", 1234);
	printf("$%8.9d$\t%%8.9d\n", 1234);

	printf("==================\n");

	printf("$%-8.1d$\t%%-8.1d\n", 1234);
	printf("$%-8.2d$\t%%-8.2d\n", 1234);
	printf("$%-8.3d$\t%%-8.3d\n", 1234);
	printf("$%-8.4d$\t%%-8.4d\n", 1234);
	printf("$%-8.5d$\t%%-8.5d\n", 1234);
	printf("$%-8.6d$\t%%-8.6d\n", 1234);
	printf("$%-8.7d$\t%%-8.7d\n", 1234);
	printf("$%-8.8d$\t%%-8.8d\n", 1234);
	printf("$%-8.9d$\t%%-8.9d\n", 1234);

	printf("==================\n");

	printf("$%0.8d$\t%%0.8d\n", 1234);
	printf("$%1.8d$\t%%1.8d\n", 1234);
	printf("$%2.8d$\t%%2.8d\n", 1234);
	printf("$%3.8d$\t%%3.8d\n", 1234);
	printf("$%4.8d$\t%%4.8d\n", 1234);
	printf("$%5.8d$\t%%5.8d\n", 1234);
	printf("$%6.8d$\t%%6.8d\n", 1234);
	printf("$%7.8d$\t%%7.8d\n", 1234);
	printf("$%8.8d$\t%%8.8d\n", 1234);
	printf("$%8.8d$\t%%8.8d\n", 1234);

	printf("==================\n");

	printf("$%-1.8d$\t%%-1.8d\n", 1234);
	printf("$%-2.8d$\t%%-2.8d\n", 1234);
	printf("$%-3.8d$\t%%-3.8d\n", 1234);
	printf("$%-4.8d$\t%%-4.8d\n", 1234);
	printf("$%-5.8d$\t%%-5.8d\n", 1234);
	printf("$%-6.8d$\t%%-6.8d\n", 1234);
	printf("$%-7.8d$\t%%-7.8d\n", 1234);
	printf("$%-8.8d$\t%%-8.8d\n", 1234);
	printf("$%-9.8d$\t%%-9.8d\n", 1234);

	printf("==================\n");

	printf("$%-1.8x$\t%%-1.8x\n", 291);
	printf("$%-2.8x$\t%%-2.8x\n", 291);
	printf("$%-3.8x$\t%%-3.8x\n", 291);
	printf("$%-4.8x$\t%%-4.8x\n", 291);
	printf("$%-5.8x$\t%%-5.8x\n", 291);
	printf("$%-6.8x$\t%%-6.8x\n", 291);
	printf("$%-7.8x$\t%%-7.8x\n", 291);
	printf("$%-8.8x$\t%%-8.8x\n", 291);
	printf("$%-9.8x$\t%%-9.8x\n", 291);

	int a = 0;

	printf("==================\n");

	printf("$%11p$\t%%11p\n", &a);
	printf("$%12p$\t%%12p\n", &a);
	printf("$%13p$\t%%13p\n", &a);
	printf("$%14p$\t%%14p\n", &a);
	printf("$%15p$\t%%15p\n", &a);
	printf("$%16p$\t%%16p\n", &a);
	printf("$%17p$\t%%17p\n", &a);
	printf("$%18p$\t%%18p\n", &a);
	printf("$%19p$\t%%19p\n", &a);

	printf("==================\n");

	printf("$%-11p$\t%%-11p\n", &a);
	printf("$%-12p$\t%%-12p\n", &a);
	printf("$%-13p$\t%%-13p\n", &a);
	printf("$%-14p$\t%%-14p\n", &a);
	printf("$%-15p$\t%%-15p\n", &a);
	printf("$%-16p$\t%%-16p\n", &a);
	printf("$%-17p$\t%%-17p\n", &a);
	printf("$%-18p$\t%%-18p\n", &a);
	printf("$%-19p$\t%%-19p\n", &a);

	return (0);
}
