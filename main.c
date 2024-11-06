#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "utils.h"

int login(char* usuario);
void registrarAccion(const char* usuario, const char* accion);
const char *figuras[] = {
    "Triángulo", "Paralelogramo", "Cuadrado", "Rectángulo", "Rombo",
    "Trapecio", "Círculo", "Polígono regular", "Cubo", "Cuboide",
    "Cilindro", "Cilindro recto", "Esfera", "Cono circular recto"};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char usuario[50];

    while (1) {
        if (login(usuario)) {
            registrarAccion(usuario, "Ingreso exitoso al sistema");
            break;
        } else {
            registrarAccion(usuario, "Ingreso fallido usuario/clave erróneo");
            printf("Usuario o clave incorrectos. Inténtelo de nuevo.\n");
        }
    }

    int opcion;
    int continuar;
    do
    {
        opcion = solicitarFigura();

        switch (opcion)
        {
        case 1:
            printf("Elegiste triángulo:\n");
            double base_triangulo;
            double altura_triangulo;
            printf("Ingresa la base:\n");
            scanf("%lf", &base_triangulo);
            printf("Ingresa la altura:\n");
            scanf("%lf", &altura_triangulo);
            calcularTriangulo(base_triangulo, altura_triangulo);
            break;

        case 2:
            printf("Elegiste paralelogramo:\n");
            double lado1_paralelogramo;
            double lado2_paralelogramo;
            double altura_paralelogramo;
            printf("Ingresa la base/lado 1:\n");
            scanf("%lf", &lado1_paralelogramo);
            printf("Ingresa el lado 2:\n");
            scanf("%lf", &lado2_paralelogramo);
            printf("Ingresa la altura:\n");
            scanf("%lf", &altura_paralelogramo);
            calcularParalelogramo(lado1_paralelogramo, lado2_paralelogramo, altura_paralelogramo);
            break;

        case 3:
            printf("Elegiste cuadrado:\n");
            double lado_cuadrado;
            printf("Ingresa el lado:\n");
            scanf("%lf", &lado_cuadrado);
            calcularCuadrado(lado_cuadrado);
            break;

        case 4:
            printf("Elegiste rectángulo:\n");
            double largo;
            double ancho;
            printf("Ingresa el largo:\n");
            scanf("%lf", &largo);
            printf("Ingresa el ancho:\n");
            scanf("%lf", &ancho);
            calcularRectangulo(largo, ancho);
            break;

        case 5:
            printf("Elegiste rombo:\n");
            double diagonal_mayor;
            double diagonal_menor;
            printf("Ingresa la diagonal mayor:\n");
            scanf("%lf", &diagonal_mayor);
            printf("Ingresa la diagonal menor:\n");
            scanf("%lf", &diagonal_menor);
            calcularRombo(diagonal_mayor, diagonal_menor);
            break;

        case 6:
            printf("Elegiste trapecio:\n");
            double base_mayor;
            double base_menor;
            double altura_trapecio;
            printf("Ingresa la base mayor:\n");
            scanf("%lf", &base_mayor);
            printf("Ingresa la base menor:\n");
            scanf("%lf", &base_menor);
            printf("Ingresa la altura:\n");
            scanf("%lf", &altura_trapecio);
            calcularTrapecio(base_mayor, base_menor, altura_trapecio);
            break;

        case 7:
            printf("Elegiste círculo:\n");
            double radio;
            printf("Ingresa el radio:\n");
            scanf("%lf", &radio);
            calcularCirculo(radio);
            break;

        case 8:
            printf("Elegiste polígono regular:\n");
            double lado_poligono;
            double numero_lados;
            double apotema;
            printf("Ingresa el número de lados:\n");
            scanf("%lf", &numero_lados);
            printf("Ingresa la longitud de un lado:\n");
            scanf("%lf", &lado_poligono);
            printf("Ingresa el apotema:\n");
            scanf("%lf", &apotema);
            calcularPoligonoRegular(numero_lados, lado_poligono, apotema);
            break;

        case 9:
            printf("Elegiste cubo:\n");
            double lado_cubo;
            printf("Ingresa el lado del cubo:\n");
            scanf("%lf", &lado_cubo);
            calcularCubo(lado_cubo);
            break;

        case 10:
            printf("Elegiste cuboide:\n");
            double largo_cuboide;
            double ancho_cuboide;
            double alto_cuboide;
            printf("Ingresa el largo:\n");
            scanf("%lf", &largo_cuboide);
            printf("Ingresa el ancho:\n");
            scanf("%lf", &ancho_cuboide);
            printf("Ingresa el alto:\n");
            scanf("%lf", &alto_cuboide);
            calcularCuboide(largo_cuboide, ancho_cuboide, alto_cuboide);
            break;

        case 11:
            printf("Elegiste cilindro:\n");
            double radio_cilindro;
            double altura_cilindro;
            printf("Ingresa el radio:\n");
            scanf("%lf", &radio_cilindro);
            printf("Ingresa la altura:\n");
            scanf("%lf", &altura_cilindro);
            calcularCilindro(radio_cilindro, altura_cilindro);
            break;

        case 12:
            printf("Elegiste cilindro recto:\n");
            double radio_cilindro_recto;
            double altura_cilindro_recto;
            printf("Ingresa el radio:\n");
            scanf("%lf", &radio_cilindro_recto);
            printf("Ingresa la altura:\n");
            scanf("%lf", &altura_cilindro_recto);
            calcularCilindroRecto(radio_cilindro_recto, altura_cilindro_recto);
            break;

        case 13:
            printf("Elegiste esfera:\n");
            double radio_esfera;
            printf("Ingresa el radio de la esfera:\n");
            scanf("%lf", &radio_esfera);
            calcularEsfera(radio_esfera);
            break;

        case 14:
            printf("Elegiste cono circular recto:\n");
            double radio_cono;
            double altura_cono;
            printf("Ingresa el radio del cono:\n");
            scanf("%lf", &radio_cono);
            printf("Ingresa la altura del cono:\n");
            scanf("%lf", &altura_cono);
            calcularConoCircularRecto(radio_cono, altura_cono);
            break;

        default:
            printf("No elegiste una opción válida :(\n");
            break;
        }

        registrarAccion(usuario, figuras[opcion - 1]);
        continuar = preguntarContinuar();

    } while (continuar == 1);

    registrarAccion(usuario, "Salida del sistema");
    return 0;
}

int login(char* usuario) {
    char clave[50], usuario_archivo[50], clave_archivo[50];
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }
    printf("Usuario: ");
    scanf("%s", usuario);
    printf("Clave: ");
    scanf("%s", clave);
    while (fscanf(file, "%s %s", usuario_archivo, clave_archivo) != EOF) {
        if (strcmp(usuario, usuario_archivo) == 0 && strcmp(clave, clave_archivo) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void registrarAccion(const char* usuario, const char* accion) {
    FILE *file = fopen("bitacora.txt", "a");
    if (file == NULL) {
        perror("Error al abrir el archivo de bitácora");
        return;
    }
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(file, "%04d/%02d/%02d: %s - %s\n",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            usuario, accion);

    fclose(file);
}

