#include<bits/stdc++.h>
using namespace std;
struct nodo{
	int dato;
	struct nodo *izq, *der;
};
typedef struct nodo *tArbol;

void insertar(tArbol &arbol, int num){
	if(arbol == NULL){
		arbol = new(struct nodo);
		arbol->dato = num;
		arbol->der = NULL;
		arbol->izq = NULL;
		return;
	}
	if(num < arbol->dato){
		insertar(arbol->izq,num);
	}
	else if(num > arbol->dato){
		insertar(arbol->der,num);		
	}
}

void mostrar(tArbol arbol){
	if(arbol!=NULL){
		cout<<arbol->dato<<" ";
		mostrar(arbol->izq);
		mostrar(arbol->der);
	}
}

int main(){
	tArbol arbol=NULL;
	int num;
	for(;;){
		cin>>num;
		if(num==-1) break;
		insertar(arbol,num);
	}
	cout<<endl;
	mostrar(arbol);
	return 0;
}
