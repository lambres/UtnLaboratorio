/* pedir numeros hasta que el usuario ingrese 888 y dar el maximo y minimo*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
int main(void)
{
    int maximo;
    int minimo;
    int bufferInt;

    int flag = TRUE;

    do
    {
        printf("IN NUMERO:(Con 888 termina)\n");
        scanf("%d", &bufferInt);
        if (flag == TRUE)
        {
            maximo = bufferInt;
            minimo = bufferInt;
            flag = FALSE;
        }
        else
        {
            if (bufferInt == 888)
            {
                break;
            }
            else
            {
                if (bufferInt > maximo)
                {
                    maximo = bufferInt;
                }
                if (bufferInt < minimo)
                {
                    minimo = bufferInt;
                }
            }
        }
    }while (TRUE);

    printf("El maximo es: %d y el minimo es: %d\n", maximo, minimo);
    return 0;
}
