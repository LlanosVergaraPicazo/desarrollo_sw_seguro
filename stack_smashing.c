#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funcion vulnerable: provoca stack smashing
void vulnerable_function(const char *input) {
    char buffer[20];
    printf("[Vulnerable] Copiando datos sin control de tama\u00f1o...\n");
    strcpy(buffer, input); // Desborda si input > 20 caracteres
    printf("Contenido del buffer: %s\n", buffer);
}

// Funcion segura: controla el tama\u00f1o de la copia
void safe_function(const char *input) {
    char buffer[20];
    printf("[Seguro] Copiando datos con validaci\u00f3n de tama\u00f1o...\n");
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Contenido del buffer: %s\n", buffer);
}

int main() {
    char user_input[200];

    printf("Introduce una cadena: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len-1] == '\n') {
            user_input[len-1] = '\0';
        }

        printf("\n-- Ejecucion de funcion vulnerable --\n");
        vulnerable_function(user_input);

        printf("\n---\n\n");

        printf("-- Ejecucion de funcion segura --\n");
        safe_function(user_input);
    } else {
        printf("Error al leer la entrada.\n");
    }

    return 0;
}
