#include <bits/stdc++.h>
using namespace std;
struct nodo{
	int peso;		//total
	int desc;		//descargado
	int prio;		//prioridad
	string nomb;	//nombre
	struct nodo *sgte;	
};
typedef struct nodo *tCola;
struct nodo2{
	int peso;		//total
	string nomb;	//nombre
	struct nodo2 *sgte;	
};
typedef struct nodo2 *tLista;


int lim=3;
//tiempo
//clock_t start;
//int diff;

void mostrar(tCola cola,tLista lista){
	tCola t=cola;
	tLista t2=lista;
	string pr;
	int i=1;
	if(t != NULL){
		cout<<"COLA DE DESCARGAS";
		cout<<"\n==========================================================================\n";	
		cout<<setw(2)<<"N"<<setw(15)<<"NOMBRE"<<setw(12)<<"PESO"<<setw(15)<<"PRIORIDAD"<<setw(15)<<"DESCARGADO"<<setw(15)<<"ESTADO"<<endl;
		while(t != NULL){
			switch(t->prio){
				case 1:pr="ALTA";break;
				case 2:pr="MEDIA";break;
				case 3:pr="BAJA";break;
			}
			cout<<setw(2)<<i<<setw(15)<<t->nomb<<setw(10)<<t->peso<<"MB"<<setw(15)<<pr<<setw(13)<<t->desc<<"MB"<<setw(14)<<((t->desc)*100/(t->peso))<<"%"<<endl;
			t = t->sgte;
			i++;
		}
	}
	i=1;
	
	if(t2 != NULL){
		cout<<"\n==========================================================================\n";
		cout<<"DESCARGADO...";
		cout<<"\n==========================================================================\n";
		cout<<setw(2)<<"N"<<setw(15)<<"NOMBRE"<<setw(12)<<"PESO"<<endl;
		while(t2 != NULL){
			cout<<setw(2)<<i<<setw(15)<<t2->nomb<<setw(10)<<t2->peso<<"MB"<<endl;
			t2 = t2->sgte;
			i++;
		}
	}
}

void eliminarI(tCola &cola){
	tCola t = cola;
	cola=t->sgte;
	delete(t);
}

void eliminarP(tCola &cola, int pos){
	tCola t=cola, p;
	if(pos==1){
		eliminarI(cola);
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

void insertarI(tCola &cola,tCola aux){
	tCola nuevo = new (struct nodo);
	nuevo->nomb=aux->nomb;
	nuevo->peso=aux->peso;
	nuevo->prio=aux->prio;
	nuevo->desc=aux->desc;
	nuevo->sgte = cola;
	cola = nuevo;	
}

void insertarIC(tLista &lista,tCola aux){
	tLista nuevo = new (struct nodo2);
	nuevo->nomb=aux->nomb;
	nuevo->peso=aux->peso;
	nuevo->sgte = lista;
	lista = nuevo;	
}

void insertarF(tCola &cola,tCola aux){
	tCola nuevo = new (struct nodo), temp = cola;
	nuevo->nomb=aux->nomb;
	nuevo->peso=aux->peso;
	nuevo->prio=aux->prio;
	nuevo->desc=aux->desc;
	nuevo->sgte = NULL;
	if(temp == NULL){
		cola = nuevo;
	}
	else{
		while(temp->sgte != NULL){
			temp = temp->sgte;
		}
		temp->sgte = nuevo;
	}
	cout<<"XXX";
}

void insertarP(tCola &cola,tCola aux,int pos){
	tCola nuevo = new (struct nodo), temp = cola;
	nuevo->nomb=aux->nomb;
	nuevo->peso=aux->peso;
	nuevo->prio=aux->prio;
	nuevo->desc=aux->desc;
	nuevo->sgte = NULL;
	if(pos==1){
		if(cola==NULL){
			cout<<"Posicion no encontrada...";
			return;
		}
		insertarI(cola,aux);
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

void agregarC(tCola &cola){
	tCola t = new(struct nodo),temp=cola;
	cout<<"Nombre:";
	cin>> t->nomb;
	do{		
		cout<<"Peso:";
		cin>> t->peso;
	}while(t->peso <= 0);
	t->desc = 0;
	t->prio = 3;
	t->sgte = NULL;
	/*	
	if(cola == NULL){
		cola = t;
	}
	else{
		while(temp->sgte != NULL){
			temp = temp->sgte;
		}
		temp->sgte = t;
	}*/
	insertarF(cola,t);
}

void prioridad(tCola &cola){
	int num,i;
	tCola t=cola;
	if(t==NULL){
		cout<<"Lista vacia";
		return;
	}
	do{
		cout<<"Elija el numero del archivo: ";
		cin>>num;
	}while(num<=0);
	for(i=1;i<num;i++){
		t=t->sgte;
		if(t==NULL){
			cout<<"No encontrado";
			return;
		}
	}
	cout<<"Ingrese nueva prioridad [1(Alta)-2(Media)-3(Baja)]: ";
	int nPrio;
	cin>>nPrio;
	
	tCola aux = new(struct nodo);
	aux->nomb=t->nomb;
	aux->peso=t->peso;
	aux->prio=nPrio;
	aux->desc=t->desc;
	eliminarP(cola,i);

	t=cola;
	int cont=1;
	while(t!=NULL){
		if(nPrio < t->prio)
			break;
		if(t->sgte==NULL){
			insertarF(cola,aux);
			return;
		}
		cont++;
		t=t->sgte;
	}
	
	insertarP(cola,aux,cont);
	

}

void cancelarD(tCola &cola){
	int pos;
	cout<<"Ingrese posicion a borrar: ";
	cin>>pos;
	eliminarP(cola,pos);
}
/*
void limpiar(tCola &cola){
	tCola t=cola;
	if(t==NULL){
		return;
	}
	for(int i=1;;i++){
		if(t->desc==t->peso){
			eliminarP(cola,i);
		}		
		t=t->sgte;
		if(t==NULL){
			break;
		}
	}
}
*/
void moverD(tCola &cola,tLista &lista){
	tCola t=cola;
	int cont=1;
	
	//start = clock();
	//diff = ( std::clock() - start );
	int diff=1;
		
	while(t!=NULL && cont<=lim){
		t->desc = t->desc + 10;
		if(t->desc >= t->peso){
			insertarIC(lista,t);
			eliminarP(cola,cont);
		}
		cont++;
		t=t->sgte;
	}
	
}

void menu(tCola &cola,tLista &lista){
	int opc;
	do{
		system("cls");
		moverD(cola,lista);
		mostrar(cola,lista);
		cout<<"\n==========================================================================";
		cout<<"\nMENU";
		cout<<"\n1.Agregar a la cola de descargas";
		cout<<"\n2.Cancelar descarga";
		cout<<"\n3.Limpiar descargados";
		cout<<"\n4.Cambiar prioridad";
		cout<<"\n5.Salir";
		cout<<"\nOpcion->";
		cin>>opc;
		switch(opc){
			case 1 : agregarC(cola);break;
			case 2 : cancelarD(cola);break;
			/*case 3 : limpiar(cola);break;*/
			case 4 : prioridad(cola);break;
		}
	}while(opc!=5);
}

int main(){
	tCola cola=NULL;
	tLista lista=NULL;
	menu(cola,lista);
	system("pause");
	return 0;
}



