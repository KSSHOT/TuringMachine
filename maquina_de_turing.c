#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Función para generar un número aleatorio en un rango
int aleatorio_en_rango(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

// Función para generar una cadena aleatoria con la estructura correcta
void cadena_aleatoria(int longitud1, int longitud2, char destino[]) {
    int x;

    // El formato de la cadena debe ser *|...|*|...|*
    // Inicializar el destino
    destino[0] = '*';

    // Añadir los caracteres '|' entre los asteriscos
    for (x = 0; x < longitud1; x++) {
        destino[x + 1] = '|';
    }
    destino[x + 1] = '*';

    // Añadir los caracteres '|' entre el segundo asterisco y el final
    for (int y = 0; y < longitud2; y++) {
        destino[x + 2 + y] = '|';
    }
    destino[x + 2 + longitud2] = '*';
    destino[x + 3 + longitud2] = '\0';  // Finalizar la cadena
}

// Función para mostrar el menú y obtener la elección del usuario
int menu() {
    int eleccion;
    printf("\n1 = Ingresar cadena");
    printf("\n2 = Generar cadena");
    printf("\n3 = Salir\n");
    scanf("%d", &eleccion);
    while (getchar() != '\n');  // Limpiar el buffer de entrada
    return eleccion;
}

// Función para imprimir el estado actual de la máquina de Turing
void imprimir(char *cad, char c, int est, int i) {
    FILE *f = fopen("Maquina_de_Turing.txt", "a");
    int x;
    int z = 0;

    if (!f) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    // Imprimir estado y contenido de la cadena
    printf("\n\nEstado: %d\n", est);
    fprintf(f, "\n\nEstado: %d\n", est);

    for (x = 0; x < strlen(cad); x++) {
        printf("%c ", cad[x]);
        fprintf(f, "%c ", cad[x]);
    }
    printf("\n");
    fprintf(f, "\n");

    // Imprimir la posición actual de la cabeza
    for (x = 0; x < i; x++) {
        printf("  ");
        fprintf(f, "  ");
    }

    for (x = i; x < strlen(cad); x++) {
        if (cad[x] == c && z == 0) {
            printf("^ ");
            fprintf(f, "^ ");
            z++;
        } else {
            printf("  ");
            fprintf(f, "  ");
        }
    }

    fflush(f);
    fclose(f);

    // Pausa solo si la longitud de la cadena es menor que 10
    if (strlen(cad) <= 15) {
        sleep(1);
    }
}

// Función que simula el comportamiento de una máquina de Turing
void TuringM(char cad[]) {
    int estado = 1;  // Estado inicial
    int i = 0;  // Posición en la cadena
    int indicador = 0;  // Flag para aceptar/rechazar la cadena

    // Imprimir la cadena inicial
    for (int x = 0; x < strlen(cad); x++) {
        printf("%c ", cad[x]);
    }

    while (indicador == 0 && estado != 0) {
        switch (estado) {
            case 1:
                if (cad[i] == '*') {
                    cad[i] = 'X';
                    imprimir(cad, 'X', estado, i);
                    i++;
                    estado = 2;
                } else {
                    estado = 0;
                }
                break;
            case 2:
                if (cad[i] == '*') {
                    cad[i] = '*';
                    imprimir(cad, '*', estado, i);
                    i++;
                    estado = 3;
                } else if (cad[i] == '|') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i++;
                    estado = 2;
                } else {
                    estado = 0;
                }
                break;
            case 3:
                if (cad[i] == '*') {
                    cad[i] = 'X';
                    imprimir(cad, 'X', estado, i);
                    i--;
                    estado = 4;
                } else if (cad[i] == '|') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i++;
                    estado = 3;
                } else {
                    estado = 0;
                }
                break;
            case 4:
                if (cad[i] == '*') {
                    cad[i] = '*';
                    imprimir(cad, '*', estado, i);
                    i--;
                    estado = 4;
                } else if (cad[i] == '|') {
                    cad[i] = 'a';
                    imprimir(cad, 'a', estado, i);
                    i++;
                    estado = 5;
                } else if (cad[i] == 'X') {
                    cad[i] = 'X';
                    imprimir(cad, 'X', estado, i);
                    i++;
                    estado = 7;
                } else {
                    estado = 0;
                }
                break;
            case 5:
                if (cad[i] == '*') {
                    cad[i] = '*';
                    imprimir(cad, '*', estado, i);
                    i++;
                    estado = 5;
                } else if (cad[i] == '|') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i++;
                    estado = 5;
                } else if (cad[i] == 'X') {
                    cad[i] = 'X';
                    imprimir(cad, 'X', estado, i);
                    i++;
                    estado = 5;
                } else if (cad[i] == '\0') {
                    cad[i] = '|';
                    cad[i + 1] = '\0';
                    imprimir(cad, '|', estado, i);
                    i--;
                    estado = 6;
                } else {
                    estado = 0;
                }
                break;
            case 6:
                if (cad[i] == '*') {
                    cad[i] = '*';
                    imprimir(cad, '*', estado, i);
                    i--;
                    estado = 6;
                } else if (cad[i] == '|') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i--;
                    estado = 6;
                } else if (cad[i] == 'X') {
                    cad[i] = 'X';
                    imprimir(cad, 'X', estado, i);
                    i--;
                    estado = 6;
                } else if (cad[i] == 'a') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i--;
                    estado = 4;
                } else {
                    estado = 0;
                }
                break;
            case 7:
                if (cad[i] == '*') {
                    cad[i] = '*';
                    imprimir(cad, '*', estado, i);
                    i++;
                    estado = 8;
                } else if (cad[i] == '|') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i++;
                    estado = 7;
                } else {
                    estado = 0;
                }
                break;
            case 8:
                if (cad[i] == 'X') {
                    cad[i] = '*';
                    imprimir(cad, '*', estado, i);
                    i++;
                    estado = 8;
                } else if (cad[i] == '|') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i++;
                    estado = 8;
                } else if (cad[i] == '\0') {
                    cad[i] = '*';
                    cad[i + 1] = '\0';
                    imprimir(cad, '*', estado, i);
                    i--;
                    estado = 9;
                } else {
                    estado = 0;
                }
                break;
            case 9:
                if (cad[i] == '*') {
                    cad[i] = '*';
                    imprimir(cad, '*', estado, i);
                    i--;
                    estado = 9;
                } else if (cad[i] == '|') {
                    cad[i] = '|';
                    imprimir(cad, '|', estado, i);
                    i--;
                    estado = 9;
                } else if (cad[i] == 'X') {
                    cad[i] = '*';
                    indicador = 1;
                    imprimir(cad, '|', estado, i);
                    printf("\nCADENA ACEPTADA\n");
                    estado = 9;
                } else {
                    estado = 0;
                }
                break;
        }
    }

    if (indicador == 0 || estado == 0) {
        printf("\nCADENA RECHAZADA\n");
    }
}

// Función principal
int main() {
    char cadena[100];  // Cadena para almacenar la entrada del usuario
    int longitud1, longitud2;
    int eleccion;

    srand(time(NULL));  // Inicializar el generador de números aleatorios

    // Abrir el archivo para escribir el registro de la máquina de Turing
    FILE *f = fopen("Maquina_de_Turing.txt", "w");
    if (!f) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    fclose(f);

    // Menú principal
    while ((eleccion = menu()) != 3) {
        switch (eleccion) {
            case 1:
                printf("Ingresa una cadena: ");
                scanf("%s", cadena);
                TuringM(cadena);
                break;
            case 2:
                printf("Ingresa la longitud del primer segmento: ");
                scanf("%d", &longitud1);
                printf("Ingresa la longitud del segundo segmento: ");
                scanf("%d", &longitud2);
                cadena_aleatoria(longitud1, longitud2, cadena);
                printf("Cadena generada: %s\n", cadena);
                TuringM(cadena);
                break;
            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
        }
    }

    return 0;
}