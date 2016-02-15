#include <iostream>
#include <stdlib.h>
using namespace std;
struct nodo{
	int valor;
	struct nodo *sgte;
};
typedef struct nodo *tLista;

void mostrar(tLista lista){
	tLista temp = lista;
	while(temp!=NULL){
		cout<<temp->valor<<" ";
		temp = temp->sgte;
	}
	cout<<endl;
}

void insertarI(tLista &lista,int valor){
	tLista nuevo = new (struct nodo);
	nuevo->valor = valor;
	nuevo->sgte = lista;
	lista = nuevo;	
}
void insertarF(tLista &lista,int valor){
	tLista nuevo = new (struct nodo), temp = lista;
	nuevo->valor = valor;
	nuevo->sgte = NULL;
	if(temp == NULL){
		lista = nuevo;
	}else{
		while(temp->sgte != NULL){
			temp = temp->sgte;
		}
		temp->sgte = nuevo;
	}
}
void insertarP(tLista &lista,int valor,int pos){
	tLista nuevo = new (struct nodo), temp = lista;
	nuevo->valor = valor;
	nuevo->sgte = NULL;
	if(pos==1){
		if(lista==NULL){
			cout<<"Posicion no encontrada...";
			return;
		}
		insertarI(lista,valor);
	}else{
		for(int i = 2; temp->sgte != NULL; i++){
			if(i==pos){
				nuevo->sgte = temp->sgte;
                temp->sgte = nuevo;
                return;
			}
			temp = temp->sgte;
		}
		cout<<"Posicion no encontrada...";
	}
}

void eliminarI(tLista &lista){
	tLista t = lista;
	lista=t->sgte;
	delete(t);
}

void eliminarF(tLista &lista){
	tLista t = lista, p;
	if(t->sgte==NULL){
		delete(t);
		lista=NULL;
		return;
	}
	while(t->sgte != NULL){
		p=t;
		t = t->sgte;
	}
	p->sgte = NULL;
	delete(t);
}

void eliminarP(tLista &lista, int pos){
	tLista t=lista, p;
	if(pos==1){
		eliminarI(lista);
		return;
	}
	for(int i=2; t->sgte != NULL; i++){
		if(i==pos){
			p = t->sgte;
			t->sgte = t->sgte->sgte;
			delete(p);
			return;
		}
		t = t->sgte;
	}
	cout<<"Posicion no encontrada...";
}

void menu(tLista &lista){
	system("color 0a");
	int opc,val,pos;
	do{
		cout<<"================"<<endl;							  /*listo*/
		cout<<"\t\tMENU"<<endl;									      /*listo*/
		cout<<"\t\t1. INSERTAR AL INICIO"<<endl;			/*listo*/
		cout<<"\t\t2. INSERTAR AL FINAL"<<endl;				/*listo*/
		cout<<"\t\t3. INSERTAR POR POSICION"<<endl;		/*listo*/
		cout<<"\t\t4. ELIMINAR AL INICIO"<<endl;			/*listo*/
		cout<<"\t\t5. ELIMINAR AL FINAL"<<endl;				/*listo*/
		cout<<"\t\t6. ELIMINAR POSICION"<<endl;				/*listo*/
		cout<<"\t\t7. ORDENAR (BURBUJA)"<<endl;					
		cout<<"\t\t8. ORDENAR (SELECCION)"<<endl;				
		cout<<"\t\t9. ORDENAR (INTERCAMBIO)"<<endl;				
		cout<<"\t\t10.ORDENAR (INSERCION)"<<endl;				
		cout<<"\t\t11.ORDENAR (SHELL SORT)"<<endl;				
		cout<<"\t\t12.ORDENAR (QUICK SORT)"<<endl;				
		cout<<"\t\t13.ORDENAR (MERGE SORT)"<<endl;				
		cout<<"\t\t14.ORDENAR (RADIX)"<<endl;					
		cout<<"\t\tIngrese opcion: ";
		cin>>opc;
		switch(opc){
			case 1: 
				cout<<"Ingrese valor: ";
				cin>>val;
				insertarI(lista,val);
				break;
			case 2: 
				cout<<"Ingrese valor: ";
				cin>>val;
				insertarF(lista,val);
				break;
			case 3: 
				cout<<"Ingrese valor: ";
				cin>>val;
				cout<<"Ingrese posicion: ";
				cin>>pos;
				insertarP(lista,val,pos);
				break;
			case 4: 
				if(lista==NULL){
					cout<<"Lista vacia";
					break;
				}
				eliminarI(lista);
				break;		
			case 5: 
				if(lista==NULL){
					cout<<"Lista vacia";
					break;
				}
				eliminarF(lista);
				break;
			case 6: 
				if(lista==NULL){
					cout<<"Lista vacia";
					break;
				}
				cout<<"Ingrese posicion: ";
				cin>>pos;
				eliminarP(lista,pos);
				break;
		}
		mostrar(lista);
	}while(opc!=10);
}

int main(){
	tLista lista = NULL;
	menu(lista);
	return 0;
}
