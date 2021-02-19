/**
Autor: Suxo Pacheco Elsa Guadalupe

Librería pila.h: contiene cuatro funciones: una es para crear la pila, 
donde todo está igualado a cero (NULL), otra que nos sirve para insertar
los datos en los nodos (tomando funciones elaboradas que están guardadas 
en la librería nodo.h) de tal forma que el primer dato que reciba, será 
el último elemento de la pila, otra función para sacar el primer elemento 
de la pila y una función para imprimir toda la pila, es decir, tener acceso 
al dato de cada nodo creado e imprimirlo.
*/



/** Es aquí donde se crea un tipo de variable que se llamará struct Pila_*/
struct Pila_
{
	struct nodo *H;
	struct nodo *T;
	int tam;
};

typedef struct Pila_ Pila; //nuestro tipo de variable la llamaremos "Pila"

/**Función initPila:
*	return init
*	
*	Aquí se inicializa la pila al reservar memoria, donde por el momento, 
*	los apuntadores *H y *T que apunta a variables tipo struct nodo valen 0 
*	y como no hay nodos todavía, tam vale 0.
*	Al final, se retorna la dirección de memoria de este espacio reservado.
*/
Pila* initPila()
{
	Pila* init;
	init=(Pila*)malloc(sizeof(Pila));
	init->H=NULL;
	init->T=NULL;
	init->tam=0;
	return init;
}

/**Función push
*	@param [in] Dato
*	@param [out] p
*	
*	Ésta tendrá como variables al apuntador *p que apunta al espacio
*	reservado hecho en initPila y un dato entero cualquiera. Se crea aux y
*	por la función "InicializarNodoDN", recibe la dirección de memoria del 
*	nodo creado allí.
*	Luego,*H tendrá la dirección del nodo (mediante aux) y se actualizan los 
*	datos: como ya existe un nodo, tam aumenta por uno y si resulta ser el 
*	primer nodo creado, el apuntador *T tendrá la dirección de ese nodo; por 
*	tanto, el primer nodo creado será considerado como el último elemento de 
*	la pila
*/
void push(Pila *p, int Dato)
{
	struct nodo* aux;
	/*Si fue el primer nodo, el apuntador *H valdrá NULL, por lo
	que la var. *sig del nodo también tendrá ese valor.*/
	aux=InicializarNodoDN(Dato, p->H);
	p->H=aux;
	p->tam++;
	if (p->tam==1)
		p->T=aux;
}

/** Función pop:
*	@param [out] p 
*	return aux
*
*	Recibe como parámetro el apuntador *p. Se encargará de eliminar el 
*	primer elemento de la pila pero tomando el dato que guarda. Si no existe 
*	ningún dato, se devolverá cero. Se crea un apuntador llamado *borrame, 
*	que apuntará al primer elemento. Luego redefiniremos al elemento sig. 
*	del primer elemento como primer elemento de la pila y "desenlazaremos" 
*	el otro nodo para después eliminarlo.
*/
int pop(Pila* p)
{
	if (p->tam==0)
		return 0;
	int aux;
	aux=p->H->dato;
	struct nodo *borrame;
	borrame=p->H;
	p->H=p->H->sig;
	borrame->sig=NULL;
	if (p->tam==1)
		p->T=NULL;
	free(borrame);
	p->tam--;
	return (aux);
}

/**Función imprimir:
*	@param [in] p
*
*	Entra en la función *p que es un apuntador que apunta al espacio de 
*	memoria creado en "initPila".
*	Se crea el apuntador *aux que contendrá la dirección a la que apunta 
*	*H (a través de *p), que es la dirección de un nodo. Es así que se 
*	imprime mínimo, un nodo. Dentro de while, *aux ahora tendrá el conte-
*	nido de *sig de ese nodo, que resulta ser la dirección de otro nodo, 
*	por lo que se repite el ciclo. 
*	En caso contrario (aux=NULL), quiere decir que ya se imprimió el 
*	último nodo y que se saldrá del ciclo.
*/
void imprimir(Pila* p)
{
	struct nodo* aux=p->H;
	int i=0;
	while (aux!=NULL)
	{
		for (i=1;i<=p->tam;i++)
		{
			printf("\nNodo %d: ",i);
			printf("%d",aux->dato);
			aux=aux->sig;
		}
	}
	printf("\n");
}
