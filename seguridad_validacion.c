#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Funcion vulnerable: ejecuta comando sin validar
void vulnerable_execute(const char *input) {
    char command[100];
    printf("[Vulnerable] Ejecutando comando sin validar...\n");
    snprintf(command, sizeof(command), "echo %s", input);
    system(command); // Muy peligroso si input contiene caracteres especiales
}

// Funcion segura: solo permite comandos predefinidos
void safe_execute(const char *input) {
    printf("[Seguro] Validando comando antes de ejecutar...\n");

    if (strcmp(input, "hola") == 0 || strcmp(input, "adios") == 0) {
        char command[100];
        snprintf(command, sizeof(command), "echo %s", input);
        system(command);
    } else {
        printf("Comando no permitido por razones de seguridad.\n");
    }
}

int main() {
    char user_input[100];

    printf("Introduce un comando (ej: hola o adios): ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len-1] == '\n') {
            user_input[len-1] = '\0';
        }

        printf("\n-- Ejecucion vulnerable --\n");
        vulnerable_execute(user_input);

        printf("\n---\n\n");

        printf("-- Ejecucion segura --\n");
        safe_execute(user_input);
    } else {
        printf("Error al leer la entrada.\n");
    }

    return 0;
}