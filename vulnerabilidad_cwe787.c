/* 
 * Programa demostrativo de CWE-787 (Out-of-bounds Write)
 * Asignatura: Desarrollo de Software Seguro (31105147 - UNED)
 * Basado en principios de "Secure Coding in C and C++".
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funcion vulnerable
void vulnerable_copy(const char *input) {
    char buffer[10];
    printf("[Vulnerable] Copiando datos sin comprobaciones...\n");
    strcpy(buffer, input); // Peligroso: no hay verificación del tamaño
    printf("Contenido del buffer: %s\n", buffer);
}


// Funcion segura
void safe_copy(const char *input) {
    char buffer[10];
    printf("[Seguro] Copiando datos con límite de tamaño...\n");
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Asegura la terminación
    printf("Contenido del buffer: %s\n", buffer);
}

int main() {
    char user_input[100];

    printf("Introduce una cadena: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        // Eliminar salto de linea '\n' si está presente
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len - 1] == '\n') {
            user_input[len - 1] = '\0';
        }

        // Demostración de función vulnerable
        vulnerable_copy(user_input);

        printf("\n---\n\n");

        // Demostración de función segura
        safe_copy(user_input);
    } else {
        printf("Error al leer la entrada.\n");
    }

    return 0;
}
