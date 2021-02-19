#Suxo Pacheco Elsa G.
#Implementación del algoritmo de ordenamiento por pilas en Python

def OrdenamientoInterno(A):
	global cont
	pila1=[]
	pila2=[]
	if A==[]:
		return A
	pila1.append(A.pop(0))
	while(A!=[]):
		cont=cont+1
		if pila1==[]:
			pila1.append(A.pop(0))
		if A==[]:
			break
		while pila2!=[]:
			cont=cont+1
			if A[0].id>pila2[len(pila2)-1].id:
				pila1.append(pila2.pop())
			else:
				break
		if A[0].id>pila1[len(pila1)-1].id:
			pila1.append(A.pop(0))
		else:
			pila2.append(pila1.pop())

	if pila2!=[]:
		while pila2!=[]:
			cont=cont+1
			pila1.append(pila2.pop())

	return pila1