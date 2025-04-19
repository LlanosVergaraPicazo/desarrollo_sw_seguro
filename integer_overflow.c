/* 
 * Programa demostrativo de Integer Overflow
 * Asignatura: Desarrollo de Software Seguro (31105147 - UNED)
 * Basado en principios de "Secure Coding in C and C++".
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Funcion vulnerable: suma sin comprobar overflow
void vulnerable_sum(int a, int b) {
    int result = a + b;
    printf("[Vulnerable] Resultado de %d + %d = %d\n", a, b, result);
}

// Funcion segura: comprueba el overflow antes de sumar
void safe_sum(int a, int b) {
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        printf("[Seguro] Error: desbordamiento detectado al sumar %d y %d\n", a, b);
    } else {
        int result = a + b;
        printf("[Seguro] Resultado de %d + %d = %d\n", a, b, result);
    }
}

int main() {
    int a, b;

    printf("Introduce el primer numero: ");
    if (scanf("%d", &a) != 1) {
        printf("Error al leer el primer numero.\n");
        return 1;
    }

    printf("Introduce el segundo numero: ");
    if (scanf("%d", &b) != 1) {
        printf("Error al leer el segundo numero.\n");
        return 1;
    }

    printf("\n-- Suma vulnerable --\n");
    vulnerable_sum(a, b);

    printf("\n---\n\n");

    printf("-- Suma segura --\n");
    safe_sum(a, b);

    return 0;
}
