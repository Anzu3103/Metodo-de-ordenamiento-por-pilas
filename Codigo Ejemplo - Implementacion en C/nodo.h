/**
Autor: Elsa Guadalupe Suxo Pacheco

Librer�a nodo.h: contiene las funciones necesarias para 
crear un nodo a partir de recibir como par�metros
un dato de tipo int y la direcci�n de memoria de alg�n 
espacio (de otro nodo o en caso de ser el primer
nodo creado, el valor NULL) o sino, solamente con recibir 
como par�metro un dato.
*/

#include <stdio.h>
#include <stdlib.h>

/** Es aqu� donde se crea un tipo de variable que se 
llamar� struct nodo*/
struct nodo
{
	int dato;
	struct nodo *sig;
};

/**Funci�n InicializarNodoD
*	@param [in] dato
*	return init
*	
*	Esta funci�n tiene como par�metro un dato, que ser� 
*	introducido por el usuario. La diferencia respecto a 
*	"InicializarNodoDN" es que �ste tendr� siempre su apuntador
*	apuntando a NULL. Esto quiere decir que s�lo nos podr� 
*	servir como el �ltimo nodo de la lista.
*	*/
struct nodo* InicializarNodoD(int dato)
{
	struct nodo* init;
	init=(struct nodo*)malloc(sizeof(struct nodo));
	init->dato=dato;
	init->sig=NULL;
	return init;
}

/**Funci�n InicializarNodoDN
*	@param [in] sig
*	@param [in] dato
*	return init
*	
*	Lo que hace es que una vez que se le d� un n�mero y reciba 
*	una direcci�n de memoria a un espacio nulo (en caso de ser 
*	el primer nodo creado, puesto que sig=l->H y *H vale 0 por 
*	la inicializaci�n de la lista) o la de un nodo anterior, se 
*	reserva otro espacio de memoria de tipo struct nodo, en donde los
*	miembros de ese nuevo nodo almacenar� los valores de los par�metros. 
*	Al final, retorna la direcci�n de memoria de todo ese nodo.
*/
struct nodo*InicializarNodoDN (int dato, struct nodo*sig)
{
	struct nodo* init;
	init=(struct nodo*)malloc(sizeof (struct nodo));
	init->dato=dato;
	init->sig=sig; /*Es aqu� donde el *sig del nuevo nodo pueda contener 
	la direcci�n del nodo anterior o NULL si es el primero*/
	return init;
}