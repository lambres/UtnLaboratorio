#include <stdio.h>
#include <stdint.h>

int main(void)
{
    setbuf(stdout,NULL);
    int a;
    int b;
    char o;
    float f;

    printf("elsize de a es :%lu\n", sizeof(a));
    printf("elsize de b es :%lu\n", sizeof(b));
    printf("elsize de o es :%lu\n", sizeof(o));
    printf("elsize de f es :%lu\n", sizeof(f));

    printf("La direccion de A es: %p\n", &a);
    printf("La direccion de B es: %p\n", &b);

    printf("La direccion de o es: %p\n", &o);
    printf("La direccion de f es: %p\n", &f);

    return 0;
}
