/**
Autor: Suxo Pacheco Elsa Guadalupe

Librería lista.h: contiene cuatro funciones principales: una es 
para crear la lista, donde todo está igualado a cero, otra que 
nos sirve para insertar los datos en los nodos (tomando funciones 
elaboradas que están guardadas en la librería nodo.h), una función 
para imprimir toda la lista, es decir, tener acceso al dato de cada 
nodo creado e imprimirlo, y para eliminar nodos desde el principio. 
Además, fue implementada con una función que se encarga de eliminar 
el elemento intermedio de una lista.
*/
#include "nodo.h"
/** Es aquí donde se crea un tipo de variable que se llamará 
struct Lista*/
struct Lista_
{
	struct nodo *H;
	struct nodo *T;
	int tamList;
};

typedef struct Lista_ Lista;
/**Función InitLista:
*	return init
*
*	Aquí se inicializa la lista al reservar memoria, donde por 
*	el momento, los apuntadores *H y *T que apunta a variables 
*	tipo struct nodo valen 0 y como no hay nodos todavía, tamList 
*	vale 0. Al final, se retorna la dirección de memoria de este 
*	espacio reservado.
*/
Lista*InitLista()
{
	Lista* init;
	init=(Lista*)malloc(sizeof(Lista));
	init->H=NULL;
	init->T=NULL;
	init->tamList=0;
	return init;
}

/**Función InsertarP
*	@param [in] l
*	@param [in] dato
*	
*	Ésta tendrá como variables al apuntador *l que apunta al espacio 
*	reservado hecho en InitLista y un dato entero cualquiera. Se crea 
*	aux y por la función "InicializarNodoDN", recibe la dirección de 
*	memoria del nodo creado allí. Luego,*H tendrá la dirección del nodo 
*	(mediante aux) y se actualizan los datos: como ya existe un nodo, 
*	tamList aumenta por uno y si resulta ser el primer nodo creado,
*	el apuntador *T tendrá la dirección de ese nodo; por tanto, el primer 
*	nodo creado será considerado como el último elemento de la lista.
*	De esta manera, insertamos el dato desde el inicio de la lista.
*/
void insertarP(Lista *l, int dato)
{
	struct nodo* aux;
	aux=InicializarNodoDN(dato, l->H); /**Si fue el primer nodo, el apuntador 
	*H valdrá NULL, por lo que la var. *sig del nodo también tendrá ese valor.*/
	l->H=aux;
	l->tamList++;
	if (l->tamList==1)
		l->T=aux;
}

/**Función ImprimirLista:
*	@param [in] *l
*	
*	Entra en la función *l que es un apuntador que apunta al espacio 
*	de memoria creado en "InitLista". Se crea el apuntador *aux que 
*	contendrá la dirección a la que apunta *H (a través de *l), que es la
*	dirección de un nodo. Es así que se imprime mínimo, un nodo.
*	Dentro de while, *aux ahora tendrá el contenido de *sig de ese nodo, 
*	que resulta ser la dirección de otro nodo, por lo que se repite el 
*	ciclo. En caso contrario (aux=NULL), quiere decir que ya se imprimió
*	el último nodo y que se saldrá del ciclo.
*/
void ImprimirLista(Lista *l)
{
	struct nodo* aux=l->H;
	int i=0;
	while (aux!=NULL)
	{
		for (i=1;i<=l->tamList;i++)
		{
			printf("\nNodo %d: ",i);
			printf("%d",aux->dato);
			aux=aux->sig;
		}
	}
}
/**Función Borrarmedio:
*	@param [in] *l
*	return ret
*
*	Entra en la función *l que es un apuntador que apunta al espacio de 
*	memoria creado en "InitLista".
*	Lo que se hace primero es verificar si la lista está vacía, si es así, 
*	retorna 0 y se sale de la función.
*	Si tiene elementos, se checa si el tamaño de la lista es par o impar.
*	Se realizan las siguientes operaciones tal que al final retorna el 
*	valor guardado del nodo que fue borrado. 
*/
int Borrarmedio (Lista *l)
{
	int i;
	if (l->tamList==0) //En caso de que esté vacía
		return 0;
	/*Si el tamaño es par, entrará en este caso*/
	if (l->tamList%2 == 0) 
	{
		int ret, num;
		num=l->tamList/2; //Aquí se checa el num del nodo que será borrado
		struct nodo *aux, *aux2;
		aux=l->H; 
		/*Este for nos servirá para obtener la dirección de memoria del
		nodo a borrar, sabiendo el num del nodo (posición) y tambien
		ubicaremos el nodo anterior a ése*/
		for (i=1; i<num; i++)
		{
			aux2=aux;
			aux=aux->sig;
		}
		ret=aux->dato; //recuperamos el dato del nodo antes de borrar
		/*En caso de que el nodo a borrar sea el primer elemento, es 
		necesario actualizar datos de la lista*/
		if (aux==l->H)
		{
			l->H=aux->sig;
			aux->sig=NULL;
			l->tamList--;
			return ret;
		}
		aux2->sig=aux->sig; /*Cambiamos el sig del nodo anterior para 
		que apunte al nodo siguiente del que será borrado*/
		aux->sig=NULL; //Desenlazamos el nodo
		l->tamList--;
		return ret;
	}
	/*Si el tamaño es impar, entrará en este caso*/
	else 
	{
		int ret, num;
		num=(l->tamList/2)+1; /*Aquí se checa el num del nodo que será 
		borrado y como es impar, se redondea para arriba*/
		struct nodo *aux, *aux2;
		aux=l->H;
		if (l->tamList==1) //Si resulta ser el único nodo, actualizamos lista
		{
			l->H=NULL;
			l->T=NULL;
			l->tamList--;
			aux->dato=ret;
			free(aux);
			return ret;
		}
		/*Este for nos servirá para obtener la dirección de memoria del
		nodo a borrar, sabiendo el num del nodo (posición) y tambien
		ubicaremos el nodo anterior a ése*/
		for (i=1; i<num; i++)
		{
			aux2=aux;
			aux=aux->sig;
		}
		ret=aux->dato; //recuperamos dato del nodo
		aux2->sig=aux->sig; /*Cambiamos el sig del nodo anterior para 
		que apunte al nodo siguiente del que será borrado*/
		aux->sig=NULL; //Desenlazamos
		l->tamList--;
		return ret;
	}
}

/** Función sacarP:
*	@param [out] l
*	return aux
*
*	Recibe como parámetro el apuntador *l. Se encargará de eliminar el 
*	primer elemento de la lita pero tomando el dato que guarda. Si no 
*	existe ningún dato, se devolverá cero. Se crea un apuntador llamado 
*	*borrame, que apuntará al primer elemento. Luego redefiniremos al 
*	elemento sig. del primer elemento como primer elemento de la lista y 
*	"desenlazaremos" el otro nodo para después eliminarlo.
*/
int sacarP(Lista *l)
{
	if (l->tamList==0)
		return 0;
	int aux;
	aux=l->H->dato;
	struct nodo *borrame;
	borrame=l->H;
	l->H=l->H->sig;
	borrame->sig=NULL;
	if (l->tamList==1)
		l->T=NULL;
	free(borrame);
	l->tamList--;
	return (aux);
}

/** Función insertarF:
*	@param [in] l
*	@param [in] dato
*	
*	Ésta tendrá como variables al apuntador *l que apunta al espacio 
*	reservado hecho en InitLista y un dato entero cualquiera. Se crea 
*	aux y por la función "InicializarNodoD", recibe la dirección de 
*	memoria del nodo creado allí. Luego,*T tendrá la dirección del nodo 
*	(mediante aux) y se actualizan los datos: como ya existe un nodo, 
*	tamList aumenta por uno y si resulta ser el primer nodo creado,
*	el apuntador *H tendrá la dirección de ese nodo. De esta forma, 
*	insertamos el dato hasta el final de la lista.
*/
void insertarF(Lista *l, int dato)
{
	struct nodo *aux;
	aux=InicializarNodoD(dato);
	if (l->tamList==0)
	{
		l->H=aux;
		l->T=aux;
		l->tamList++;
		return;
	}
	l->T->sig=aux;
	l->T=aux;
	l->tamList++;
}
