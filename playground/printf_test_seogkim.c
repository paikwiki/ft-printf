#include <stdio.h>
int main(void){
    int p = 10;
    printf("01 printf 100s : $%s$\n", "100");
    printf("02 printf 10d  : $%d$\n", 10);
    printf("03 printf 010c : $%010c$\n", 'c');
    printf("04 printf -10c : $%-10c$\n", 'c');
    printf("05 printf 010s : $%010s$\n", "home, sweet home");
    printf("06 printf -10s : $%-10s$\n", "home, sweet home");
    printf("07 printf 020s : $%020s$\n", "home, sweet home");
    printf("08 printf -20s : $%-20s$\n", "home, sweet home");
    printf("09 printf    i : $%.10i$ d : $%.10d$\n", 1234567, 1234567);
    printf("10 printf    i : $%010i$ d : $%010d$\n", 1234567, 1234567);
    printf("11 printf    u : $%u$\n", 2147483);
    printf("12 printf    c : $%c$\n", '%');
    printf("13 printf    p : $%p$\n", &p);
    printf("14 printf    x : $%x$\n", 200);
    printf("15 printf    s : $%.s$\n", "home, sweet home");
    printf("16 printf    s : $%s$ c : $%c$\n", "1234567", '!');
    printf("17 printf $%%$ $%c$\n", '%');
}
