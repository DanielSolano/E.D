#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo
{
    int dato;
    struct _nodo *izq;
    struct _nodo *der;
} Tnodo;

Tnodo *CrearNodo(int dato)
{
    Tnodo *nuevo = (Tnodo *)malloc(sizeof(Tnodo));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

void Insertar(Tnodo *arbol, int dato)
{
    if (arbol->dato < dato)
    {
        if (arbol->der == NULL)
        {
            arbol->der = CrearNodo(dato);
        }
        else
        {
            Insertar(arbol->der, dato);
        }
    }
    else
    {
        if (arbol->izq == NULL)
        {
            arbol->izq = CrearNodo(dato);
        }
        else
        {
            Insertar(arbol->izq, dato);
        }
    }
}

void PostOrden(Tnodo *arbol)
{
    if (arbol != NULL)
    {
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        printf("%d\n", arbol->dato);
    }
}

void InOrden(Tnodo *arbol)
{
    if (arbol != NULL)
    {
        InOrden(arbol->izq);
        printf("%d \n", arbol->dato);
        InOrden(arbol->der);
    }
}

void PreOrden(Tnodo *arbol)
{
    if (arbol != NULL)
    {
        printf("%d \n", arbol->dato);
        PreOrden(arbol->izq);
        PreOrden(arbol->der);
    }
}

int main()
{
    int n = 8;
    int datos[8] = {8,
                    3,
                    1,
                    20,
                    5,
                    10,
                    7,
                    4};
    int i;
    Tnodo *arbol = CrearNodo(datos[0]);
    for (i = 1 ; i < n; i++)
    {
        Insertar(arbol, datos[i]);
    }
    printf("--- PREORDEN --- \n");
    PreOrden(arbol);
    printf("--- POSTORDEN --- \n");
    PostOrden(arbol);
    printf("--- INORDEN --- \n");
    InOrden(arbol);
}