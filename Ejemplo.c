/** Ejemplo de ordenamiento por pilas.
*	Autor: Suxo Elsa
*/

#include "lista.h"
#include "pila.h"

/**Función Ordenamiento
*   @param [in] l
*   return pila2
*   
*   Esta función es la implementación del algoritmo
*	de ordenamiento por pilas.
*/
Pila* Ordenamiento(Lista* l){
	Pila* pila1;
	Pila* pila2;
    pila1=initPila();
    pila2=initPila();
    if (l->tamList==0)
    	return pila1;

    push(pila1,sacarP(l));

    while(l->tamList!=0)
    {
        if (pila1->tam==0)
    		push(pila1,sacarP(l));
    	if (l->tamList==0)
    		break;
    	while(pila2->tam!=0)
    	{
    		if (l->H->dato > pila2->H->dato)
    			push(pila1,pop(pila2));
    		else
    			break;
    	}
    	if (l->H->dato > pila1->H->dato)
    		push(pila1,sacarP(l));
    	else
    		push(pila2,pop(pila1));
    }
    if (pila1->tam!=0)
    {
    	while(pila1->tam!=0)
    		push(pila2,pop(pila1));
    }
    free(l);
    return pila2;
}

void main(){
	int i;
	Lista* l;
	l=InitLista();
	Pila* p;

	insertarF(l,23);
	insertarF(l,2);
	insertarF(l,10);
	insertarF(l,9);
    insertarF(l,-1);
    insertarF(l,1);
	printf("La lista es la sig: \n");
	ImprimirLista(l);
	p=Ordenamiento(l);
    printf("\nLa lista ordenada es .. \n");
	imprimir(p);
    while (p->tam=0)
        pop(p);
    free(l);
}