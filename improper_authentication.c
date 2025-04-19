/* 
 * Programa mejorado de demostracion de Improper Authentication
 * Asignatura: Desarrollo de Software Seguro (31105147 - UNED)
 * Basado en principios de "Secure Coding in C and C++".
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USERNAME "admin"
#define PASSWORD "password123"

// Funcion vulnerable: autentica si el usuario empieza por "admin"
void vulnerable_authentication(const char *input_user) {
    printf("[Vulnerable] Comprobando si el nombre empieza por 'admin'...\n");
    if (strncmp(input_user, USERNAME, strlen(USERNAME)) == 0) {
        printf("Acceso concedido a %s\n", input_user);
    } else {
        printf("Acceso denegado\n");
    }
}

// Funcion segura: comprueba usuario y contrasena completos
void safe_authentication(const char *input_user, const char *input_pass) {
    printf("[Seguro] Comprobando usuario y contrasena exactos...\n");
    if (strcmp(input_user, USERNAME) == 0 && strcmp(input_pass, PASSWORD) == 0) {
        printf("Acceso concedido a %s\n", input_user);
    } else {
        printf("Acceso denegado\n");
    }
}

int main() {
    char user_input[100];
    char pass_input[100];

    printf("Introduce tu nombre de usuario: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len-1] == '\n') {
            user_input[len-1] = '\0';
        }
    }

    printf("Introduce tu contrasena: ");
    if (fgets(pass_input, sizeof(pass_input), stdin) != NULL) {
        size_t len = strlen(pass_input);
        if (len > 0 && pass_input[len-1] == '\n') {
            pass_input[len-1] = '\0';
        }
    }

    printf("\n-- Autenticacion vulnerable --\n");
    vulnerable_authentication(user_input);

    printf("\n---\n\n");

    printf("-- Autenticacion segura --\n");
    safe_authentication(user_input, pass_input);

    return 0;
}