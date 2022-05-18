/*
Hacer un programa que le pda al usuario un numero, luego la operacion matematica
por ultimo un segundo numero
Segun la operacion ingresada ejecutar una funcion (suma() resta() divison() multiplicacion())
y mostrar el resultado al usuario
*/

#include <stdint.h>
#include <stdio.h>
#include <stdio_ext.h>
int sumar(int valor1, int valor2);
int restar(int valor1, int valor2);
int multiplicar(int valor1, int valor2);
float dividir(int valor1, int valor2);

int main(void)
{
    setbuf(stdout,NULL);
    int numero1;
    int numero2;
    char operador;
    int resultado;
    float resultadoDivision;
    printf("Ingrese un número:\n");
    __fpurge(stdin);
    scanf("%d",&numero1);
    printf("Ingrese operación:\n");
    __fpurge(stdin);
    scanf("%c",&operador);
    printf("Ingrese otro numero:\n");
    __fpurge(stdin);
    scanf("%d",&numero2);

    switch (operador)
    {
    case '+':
        resultado = sumar(numero1,numero2);
        break;
    case '-':
        resultado = restar(numero1,numero2);
        break;
    case '*':
        resultado = multiplicar(numero1,numero2);
        break;
    default:
        if (numero2 == 0)
        {
            printf("No se puede dividir por 0");
        }
        else
        {
            resultadoDivision = dividir(numero1,numero2);
            break;
        }
    }
    if (operador != '/')
    {
        printf("El resultado +-* de la operacion es %d\n", resultado);
    }
    else
    {
        printf("El resultado de la operacion es %.2f\n", resultadoDivision);
    }

    return 0;
}

int sumar(int valor1, int valor2)
{
    int resultado;
    resultado = valor1 + valor2;
    return resultado;
}
int restar(int valor1, int valor2)
{
    int resultado;
    resultado = valor1 - valor2;
    return resultado;
}
int multiplicar(int valor1, int valor2)
{
    int resultado;
    resultado = valor1 * valor2;
    return resultado;
}
float dividir(int valor1, int valor2)
{
    float resultado;
    if (valor2!=0)
    {
        resultado = (float)valor1 / valor2;
    }
        return resultado;
}
