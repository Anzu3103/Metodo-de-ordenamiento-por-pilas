/**
Autor: Elsa Guadalupe Suxo Pacheco

Librería nodo.h: contiene las funciones necesarias para 
crear un nodo a partir de recibir como parámetros
un dato de tipo int y la dirección de memoria de algún 
espacio (de otro nodo o en caso de ser el primer
nodo creado, el valor NULL) o sino, solamente con recibir 
como parámetro un dato.
*/

#include <stdio.h>
#include <stdlib.h>

/** Es aquí donde se crea un tipo de variable que se 
llamará struct nodo*/
struct nodo
{
	int dato;
	struct nodo *sig;
};

/**Función InicializarNodoD
*	@param [in] dato
*	return init
*	
*	Esta función tiene como parámetro un dato, que será 
*	introducido por el usuario. La diferencia respecto a 
*	"InicializarNodoDN" es que éste tendrá siempre su apuntador
*	apuntando a NULL. Esto quiere decir que sólo nos podrá 
*	servir como el último nodo de la lista.
*	*/
struct nodo* InicializarNodoD(int dato)
{
	struct nodo* init;
	init=(struct nodo*)malloc(sizeof(struct nodo));
	init->dato=dato;
	init->sig=NULL;
	return init;
}

/**Función InicializarNodoDN
*	@param [in] sig
*	@param [in] dato
*	return init
*	
*	Lo que hace es que una vez que se le dé un número y reciba 
*	una dirección de memoria a un espacio nulo (en caso de ser 
*	el primer nodo creado, puesto que sig=l->H y *H vale 0 por 
*	la inicialización de la lista) o la de un nodo anterior, se 
*	reserva otro espacio de memoria de tipo struct nodo, en donde los
*	miembros de ese nuevo nodo almacenará los valores de los parámetros. 
*	Al final, retorna la dirección de memoria de todo ese nodo.
*/
struct nodo*InicializarNodoDN (int dato, struct nodo*sig)
{
	struct nodo* init;
	init=(struct nodo*)malloc(sizeof (struct nodo));
	init->dato=dato;
	init->sig=sig; /*Es aquí donde el *sig del nuevo nodo pueda contener 
	la dirección del nodo anterior o NULL si es el primero*/
	return init;
}