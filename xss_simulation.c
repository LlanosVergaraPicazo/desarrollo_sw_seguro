#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funcion vulnerable: inserta directamente la entrada en un HTML simulado
void vulnerable_xss(const char *input) {
    printf("[Vulnerable] Generando pagina sin filtrar entrada...\n");
    printf("<html>\n<body>\n<p>Mensaje del usuario: %s</p>\n</body>\n</html>\n", input);
}

// Funcion segura: escapa los caracteres peligrosos antes de insertar
void safe_xss(const char *input) {
    printf("[Seguro] Generando pagina con entrada filtrada...\n");
    printf("<html>\n<body>\n<p>Mensaje del usuario: ");

    for (size_t i = 0; i < strlen(input); ++i) {
        switch (input[i]) {
            case '<': printf("&lt;"); break;
            case '>': printf("&gt;"); break;
            case '"': printf("&quot;"); break;
            case '\'': printf("&#39;"); break;
            case '&': printf("&amp;"); break;
            default: putchar(input[i]);
        }
    }

    printf("</p>\n</body>\n</html>\n");
}

int main() {
    char user_input[200];

    printf("Introduce un mensaje para mostrar en la pagina: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len-1] == '\n') {
            user_input[len-1] = '\0';
        }

        printf("\n-- Pagina vulnerable --\n");
        vulnerable_xss(user_input);

        printf("\n---\n\n");

        printf("-- Pagina segura --\n");
        safe_xss(user_input);
    } else {
        printf("Error al leer la entrada.\n");
    }

    return 0;
}