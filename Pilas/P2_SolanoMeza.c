// Solano Meza Angel Daniel
// LIFO	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodos
{
	int dato;
	struct _nodos *sig;
} Tnodo;

typedef struct _lista
{
	Tnodo *tope;
} Tpila;

void Menu();
int msgs();
Tnodo *CrearNodo(int dato);
void Push(Tpila *pila, int dato);
void Pop(Tpila *pila);
void ImprimirPila(Tpila *pila);

int main()
{
	Menu();
	return 0;
}

void Menu()
{
	Tpila *pila = (Tpila *)malloc(sizeof(Tpila));
	pila->tope = NULL;
	int opcion;
	do
	{
		system("CLS");
		opcion = msgs();
		switch (opcion)
		{
		case 1:
		{
			int dato;
			printf("Ingrese el dato a insertar: ");
			scanf("%d", &dato);
			Push(pila, dato);
			break;
		}
		case 2:
		{
			Pop(pila);
			break;
		}
		case 3:
		{
			ImprimirPila(pila);
			break;
		}
		}
	} while (opcion != 0);
}

int msgs()
{
	int op;
	printf("------ PILAS ------\n");
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. MOSTRAR N\n");
	printf("0. SALIR\n");
	fflush(stdin);
	scanf("%d", &op);
	return op;
}

Tnodo *CrearNodo(int dato)
{
	Tnodo *nuevo = (Tnodo *)malloc(sizeof(Tnodo));
	nuevo->dato = dato;
	nuevo->sig = NULL;
	return nuevo;
}

void Push(Tpila *pila, int dato)
{
	Tnodo *nuevo = CrearNodo(dato);
	nuevo->sig = pila->tope;
	pila->tope = nuevo;
	printf("Dato insertado: %d\n", nuevo->dato);
}

void Pop(Tpila *pila)
{
	if (pila->tope != NULL)
	{
		Tnodo *temp;
		temp = pila->tope;
		pila->tope = pila->tope->sig;
		printf("Dato eliminado: %d\n", temp->dato);
		free(temp);
	}
	else
	{
		printf("Pila vacia\n");
	}
}

void ImprimirPila(Tpila *pila)
{
	system("CLS");
	Tnodo *temp = pila->tope;
	while (temp != NULL)
	{
		printf("%d\n", temp->dato);
		temp = temp->sig;
	}
	system("PAUSE");
}