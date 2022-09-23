#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

int main()
{
    char tab[100];
    printf("%ld\n",__PTRDIFF_MAX__);
    int *p1 = &tab[5];
    int *p2 = &tab[10];
    long p3 = p2 - p1;
    printf("%ld\n",p3);
}