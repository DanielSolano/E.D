// Solano Meza Angel Daniel
// FIFO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo {
    int dato;
    struct _nodo *sig;
} Tnodo;

typedef struct _cola {
    Tnodo *frente;
    Tnodo *final;
    unsigned int tamanio;
} Tcola;

void Menu();
int msgs();
Tnodo *CrearNodo(int dato);
void Push(Tcola *cola, int dato);
void Pop(Tcola *cola);
void Imprimircola(Tcola *cola);

int main()
{
	Menu();
	return 0;
}

void Menu()
{
	Tcola *cola = (Tcola *)malloc(sizeof(Tcola));
	cola->frente = NULL;
	cola->final = NULL;
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
			Push(cola, dato);
			break;
		}
		case 2:
		{
			Pop(cola);
			break;
		}
		case 3:
		{
			Imprimircola(cola);
			break;
		}
		}
	} while (opcion != 0);
}

int msgs()
{
	int op;
	printf("------ COLAS ------\n");
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

