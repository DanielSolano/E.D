// Solano Meza Angel Daniel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _datos
{
    char matricula[10];
    char apPat[30];
    char apMat[30];
    char nombres[40];
} Tdatos;

typedef struct _nodos
{
    struct _datos informacion;
    struct _nodos *sig;
} Tnodo;

typedef struct _lista
{
    Tnodo *cabeza;
} Tlista;

Tnodo *CrearNodo(Tdatos *informacion);
void LiberarNodo(Tnodo *nodo);
void InsertarAlPrincipio(Tlista *lista, Tdatos *informacion);
void InsertarAlFinal(Tdatos *informacion, Tlista *lista);
void InsertarPosicion(int posicion, Tlista *lista, Tdatos *informacion);
int Tamanio(Tlista *lista);
void ImprimirLista(Tlista *lista);
void EliminarNodo(Tlista *lista, int n);
void Menu();
Tdatos CrearInformacion(void);
int msgs();

int msgs()
{
    int op;
    printf("------ MENU ------\n");
    printf("1. NODO AL PRINCIPIO\n");
    printf("2. NODO AL FINAL\n");
    printf("3. NODO EN POSICION N\n");
    printf("4. MOSTRAR LISTA\n");
    printf("5. ELIMINAR NODO\n");
    printf("0. SALIR\n");
    fflush(stdin);
    scanf("%d", &op);
    return op;
}

void Menu()
{
    Tlista *lista = (Tlista *)malloc(sizeof(Tlista));
    lista->cabeza = NULL;
    int opcion;
    do
    {
        system("CLS");
        opcion = msgs();
        switch (opcion)
        {
        case 1:
        {
            // Nodo al principio
            Tdatos temporal = CrearInformacion();
            Tdatos *info = (Tdatos *)malloc(sizeof(Tdatos));
            strcpy(info->matricula, temporal.matricula);
            strcpy(info->nombres, temporal.nombres);
            strcpy(info->apPat, temporal.apPat);
            strcpy(info->apMat, temporal.apMat);
            system("CLS");
            InsertarAlPrincipio(lista, info);
            free(info);
            printf("EL NODO FUE AGREGADO CORRECTAMENTE\n");
            system("PAUSE");
            break;
        }
        case 2:
        {
            // Nodo al final
            Tdatos temporal = CrearInformacion();
            Tdatos *info = (Tdatos *)malloc(sizeof(Tdatos));
            strcpy(info->matricula, temporal.matricula);
            strcpy(info->nombres, temporal.nombres);
            strcpy(info->apPat, temporal.apPat);
            strcpy(info->apMat, temporal.apMat);
            system("CLS");
            InsertarAlFinal(info, lista);
            free(info);
            printf("EL NODO FUE AGREGADO CORRECTAMENTE\n");
            system("PAUSE");
            break;
        }
        case 3:
        {
            // Posicion N
            int posicion;
            Tdatos temporal = CrearInformacion();
            Tdatos *info = (Tdatos *)malloc(sizeof(Tdatos));
            strcpy(info->matricula, temporal.matricula);
            strcpy(info->nombres, temporal.nombres);
            strcpy(info->apPat, temporal.apPat);
            strcpy(info->apMat, temporal.apMat);
            system("CLS");
            printf("Posicion en la que insertar: ");
            scanf("%d", &posicion);
            system("CLS");
            InsertarPosicion(posicion, lista, info);
            printf("EL NODO FUE AGREGADO CORRECTAMENTE\n");
            system("PAUSE");
            break;
        }
        case 4:
        {
            system("CLS");
            // Imprimir lista
            ImprimirLista(lista);
            system("PAUSE");
            break;
        }
        case 5:
        {
            // Eliminar nodo
            int posicion, tamanio;
            system("CLS");
            printf("Posicion en la que borrar: ");
            scanf("%d", &posicion);
            tamanio = Tamanio(lista);
            if (tamanio > 1)
            {
                if (posicion > tamanio)
                {
                    printf("NODO EN POSICION NO EXISTENTE\n");
                }
                else
                {
                    EliminarNodo(lista, posicion);
                    printf("NODO ELIMINADO CORRECTAMENTE\n");
                }
            }
            else
            {
                lista->cabeza = NULL;
                printf("LISTA VACIA\n");
            }
            system("PAUSE");
            break;
        }
        }
    } while (opcion != 0);
}

int main()
{
    Menu();
    return 0;
}

Tnodo *CrearNodo(Tdatos *informacion)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    nodo->informacion = *informacion;
    nodo->sig = NULL;
    return nodo;
}

void LiberarNodo(Tnodo *nodo)
{
    free(nodo);
}

void InsertarAlPrincipio(Tlista *lista, Tdatos *informacion)
{
    Tnodo *nodo = CrearNodo(informacion);
    nodo->sig = lista->cabeza;
    lista->cabeza = nodo;
}

void InsertarAlFinal(Tdatos *informacion, Tlista *lista)
{
    if (lista->cabeza == NULL)
    {
        InsertarAlPrincipio(lista, informacion);
    }
    else
    {
        Tnodo *nodo = CrearNodo(informacion);
        Tnodo *temporal = lista->cabeza;
        while (temporal->sig != NULL)
        {
            temporal = temporal->sig;
        }
        temporal->sig = nodo;
    }
}

void InsertarPosicion(int posicion, Tlista *lista, Tdatos *informacion)
{
    int tamanio = Tamanio(lista);
    if (tamanio == 0)
    {
        InsertarAlPrincipio(lista, informacion);
    }
    else if (posicion > tamanio)
    {
        InsertarAlFinal(informacion, lista);
    }
    else if (posicion == 1)
    {
        InsertarAlPrincipio(lista, informacion);
    }
    else
    {
        Tnodo *nodo = CrearNodo(informacion);
        Tnodo *temporal = lista->cabeza;
        nodo->sig = lista->cabeza;
        for (int i = 1; i < posicion - 1; i++)
        {
            temporal = temporal->sig;
        }
        nodo->sig = temporal->sig;
        temporal->sig = nodo;
    }
}

int Tamanio(Tlista *lista)
{
    Tnodo *temporal = lista->cabeza;
    if (lista->cabeza == NULL)
    {
        return 0;
    }
    else
    {
        int tamanio = 1;
        while (temporal->sig != NULL)
        {
            temporal = temporal->sig;
            tamanio++;
        }
        return tamanio;
    }
}

void ImprimirLista(Tlista *lista)
{
    Tnodo *ptr = lista->cabeza;
    while (ptr)
    {
        printf("Matricula: %s\n", ptr->informacion.matricula);
        printf("Apellido Paterno: %s\n", ptr->informacion.apPat);
        printf("Apellido Materno: %s\n", ptr->informacion.apMat);
        printf("Nombre: %s\n", ptr->informacion.nombres);
        printf("--------------------\n");
        ptr = ptr->sig;
    }
}

void EliminarNodo(Tlista *lista, int n)
{
    Tnodo *ptr = lista->cabeza;
    Tnodo *temp = NULL;
    if (n == 0)
    {
        temp = lista->cabeza;
        lista->cabeza = lista->cabeza->sig;
        free(temp);
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            ptr = ptr->sig;
        }
        temp = ptr->sig;
        ptr->sig = ptr->sig->sig;
        free(temp);
    }
}

Tdatos CrearInformacion(void)
{
    Tdatos temporal;
    char nombre[40];
    char paterno[30];
    char materno[30];
    char matricula[10];
    system("cls");
    printf("Nombre: ");
    fflush(stdin);
    gets(nombre);
    strncpy(temporal.nombres, nombre, strlen(nombre));
    temporal.nombres[strlen(nombre)] = '\0';

    system("cls");
    printf("Apellido Paterno: ");
    fflush(stdin);
    gets(paterno);
    strncpy(temporal.apPat, paterno, strlen(paterno));
    temporal.apPat[strlen(paterno)] = '\0';

    system("cls");
    printf("Apellido Materno: ");
    fflush(stdin);
    gets(materno);
    strncpy(temporal.apMat, materno, strlen(materno));
    temporal.apMat[strlen(materno)] = '\0';

    system("cls");
    printf("Matricula: ");
    fflush(stdin);
    gets(matricula);
    strncpy(temporal.matricula, matricula, strlen(matricula));
    temporal.matricula[strlen(matricula)] = '\0';
    return temporal;
}
