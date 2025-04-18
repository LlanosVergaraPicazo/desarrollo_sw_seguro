/* 
 * Programa demostrativo de CWE-476 (NULL Pointer Dereference)
 * Asignatura: Desarrollo de Software Seguro (31105147 - UNED)
 * Basado en principios de "Secure Coding in C and C++".
 */

#include <stdio.h>
#include <stdlib.h>

// Funcion vulnerable
void vulnerable_null_dereference(int *ptr) {
    printf("[Vulnerable] Accediendo al puntero sin comprobar si es NULL...\n");
    printf("Valor: %d\n", *ptr); // Riesgo si ptr es NULL
}

// Funcion segura
void safe_null_dereference(int *ptr) {
    printf("[Seguro] Comprobando si el puntero es NULL antes de acceder...\n");
    if (ptr != NULL) {
        printf("Valor: %d\n", *ptr);
    } else {
        printf("Error: puntero NULL recibido.\n");
    }
}

int main() {
    int valor = 42;
    int *puntero_valido = &valor;
    int *puntero_nulo = NULL;


    // Caso 1: puntero valido (funciona en ambas)
    printf("-- Ejecucion con puntero valido --\n");
    vulnerable_null_dereference(puntero_valido);

    printf("\n---\n\n");

    safe_null_dereference(puntero_valido);

    printf("\n===\n\n");


    // Caso 2: puntero nulo (provoca fallo en vulnerable)
    printf("-- Ejecucion con puntero NULL --\n");
    vulnerable_null_dereference(puntero_nulo);

    printf("\n---\n\n");

    safe_null_dereference(puntero_nulo);

    printf("\n===\n\n");

    return 0;
}
