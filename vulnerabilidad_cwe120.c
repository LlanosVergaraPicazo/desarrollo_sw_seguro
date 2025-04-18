/* 
 * Programa demostrativo de CWE-120 (Classic Buffer Overflow)
 * Asignatura: Desarrollo de Software Seguro (31105147 - UNED)
 * Basado en principios de "Secure Coding in C and C++".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcion vulnerable
void vulnerable_read() {
    char buffer[20];
    printf("[Vulnerable] Introduce una cadena (puede provocar overflow):\n");
    gets(buffer); // MUY peligroso: gets no controla tamaño
    printf("Cadena introducida: %s\n", buffer);
}

// Funcion segura
void safe_read() {
    char buffer[20];
    printf("[Seguro] Introduce una cadena (entrada protegida):\n");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Eliminar salto de línea si existe
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        printf("Cadena introducida: %s\n", buffer);
    } else {
        printf("Error al leer la entrada.\n");
    }
}

int main() {
    printf("-- Ejecución de función vulnerable --\n");
    vulnerable_read();

    printf("\n---\n\n");

    printf("-- Ejecución de función segura --\n");
    safe_read();

    return 0;
}