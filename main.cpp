


#include <stdio.h>
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include <iostream>
#include <stdalign.h>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


//-------------------------------------------------------------------------------------
//							Estructura del Nodo
//-------------------------------------------------------------------------------------

struct nodos{

	char ingles[50];
	char espanol[50];
	struct nodos *der;
	struct nodos *izq;
	int Fe;

};

//-------------------------------------------------------------------------------------
//							Arbol
//-------------------------------------------------------------------------------------

typedef struct nodos Arbol;
typedef Arbol *ARBOL;
int listo=0;
char in[50],es[50];

//-------------------------------------------------------------------------------------
//							Prototipos de las funciones
//-------------------------------------------------------------------------------------

void menu();

void menu_agregar();

void menu_ingles();

void menu_espanol();

void menu_borrar();

void menu_listar();

void agregar(ARBOL  *nodoarb);

void buscar_ingles(ARBOL nodoarb);

void buscar_espanol(ARBOL nodoarb);

void listar(ARBOL nodoarb);

void rotacionddsimple(ARBOL *nodoarb);

void rotaciondidoble(ARBOL *nodoarb);

void rotaciondd2(ARBOL *nodoarb);

void rotacionii2(ARBOL *nodoarb);

void rotacioniisimple(ARBOL *nodoarb);

void rotacioniddoble(ARBOL *nodoarb);

void menor(ARBOL nodoarb);

void actualizarbi(ARBOL *nodoarb, int *ban);

void actualizarbd(ARBOL *nodoarb, int *ban);

void eliminar(ARBOL *nodoarb, int *ban);

void borrar(ARBOL *nodoarb , int *ban);

void separdor(string str);

void insertartxt();

void lector (string str);

void escribir ();

void menu_frase();

void traducir_espanol(ARBOL nodoarb);

void escribir(char *x);

void traducir_ingles(ARBOL nodoarb);

void write(char *x);

//-------------------------------------------------------------------------------------
//						    	PROGRAMA PRINCIPAL
//-------------------------------------------------------------------------------------

int main()
{
	char opc='1';
	int ban=1;
	ARBOL raiz=NULL;
	do
		{
			menu();
			cin>>opc;
			switch(opc){
						case '1':
								menu_agregar();
							    cout<<"Introduzca Palabra en Ingles : ";
								cin>>in;
								cout<<"Introduzca Palabra en Espanol : ";
								cin>>es;
								agregar(&raiz);
							    break;

						case '2':
								menu_borrar();
								cout<<"Que Palabra en Ingles desea Borrar? : ";
								cin>>in;
								borrar(&raiz,&ban);
								cout<<"Elemento Borrado!";
							    break;

						case '3':
							    menu_ingles();
								cout<<"Que Palabra en Ingles desea Buscar? : ";
								cin>>in;
								listo=0;
								buscar_ingles(raiz);
								if (listo==0)
									cout<<"Elemento no encontrado.";
								getch();
								listo=0;
								break;

						case '4':

								menu_espanol();
								cout<<"Que Palabra en Espanol desea Buscar? : ";
								cin>>es;
								listo=0;
								buscar_espanol(raiz);
								if (listo==0)
									cout<<"Elemento no encontrado.";
								getch();
								listo=0;
								break;

						case '5':

								menu_listar();
								listar(raiz);
								getch();
							    break;

						case '6':{
						    ifstream diccionario1;
						    string texto;
						    //string x;
						    diccionario1.open("Diccionario.txt",ios::in);

						    if(diccionario1.fail()){
                                cout<<"No se puede abrir el archivo."<<endl;
                            exit(1);
                            }

                            while(!diccionario1.eof()){
                                getline(diccionario1,texto);
                                cout<<"Linea: "<< texto <<endl;
                                string word = "";
                                int cont = 0;
                                char arr[50],vacio[50];
                                for (const auto x : texto){
                                    //cout<<"x: "<<x<<endl;
                                    //system("pause");
                                    if (x == ' '){
                                        cout << "Palabra en el for: " << word << endl;
                                        word = "";
                                        //cout<<"x: "<<x<<endl;
                                        //system("pause");
                                        if (cont==1){
                                            strcpy(es,arr);
                                            cont++;
                                            cout<<"Palabra ES: "<<es<<endl;
                                            }
                                        if (cont==0){
                                            strcpy(in,arr);
                                            cont++;
                                            cout<<"Palabra IN: "<<in<<endl;
                                            }
                                        }
                                    else {
                                        word = word + x;
                                        strcpy(arr, word.c_str());
                                        }
                                    }
                                agregar(&raiz);
                                cout << "Palabras insertadas: " <<endl;
                                cout<<"Ingles: "<< in << "   -   Espanol: " << es << endl;
                                //agregar(&raiz);
                                strcpy(es,vacio);
                                strcpy(in,vacio);
                                cout << "Fin de la linea.********************************************************" << endl;
                                //system("pause");
                                }
                            diccionario1.close();
                            break;
                        }

                        case '7':{
                            ifstream archivo;
                            string aux,a[9999];
	                        char aes[50],vacio[50];
	                        int cont = 0;
	                        archivo.open("Oracion Español.txt",ios::in);
	                        if (archivo.fail())
	                        {
	                        	cout<<"No se pudo abrir el archivo."<<endl;
	                        	exit(1);
	                        }
	                        while(!archivo.eof())
	                        {
	                        	getline(archivo,aux);
	                        }
	                        archivo.close();
	                        stringstream input_stringstream(aux);
	                        char delimitador = ' ';
                            while (getline(input_stringstream, aux, delimitador))
                            {
                                a[cont] = aux;
                                cont++;
                                //cout<<a[cont]<<"  hay algo aqui?   ";
                                //system("pause");
                            }
                            for (int i = 0;i<=cont;i++)
                            {
                                cout<<a[i]<<' '; // Aca seria la busqueda, el a[i] te va tirando palabra por palabra asi que siendo super simple seria algo como busqueda(a[i])
                                strcpy(aes,a[i].c_str());
                                //cout<<*aes<<" ";
                                //strcpy(aes,a[i].c_str());
                                strcpy(es,aes);
                                //cout<<es<<" es ";
                                //system("pause");
                                //listo=0;
                                traducir_espanol(&*raiz);
                                strcpy(es,vacio);
                                strcpy(aes,vacio);
                            }
                            cout<< "\n";
                            break;
                        }

                        case '8':{
                            //cout<<"el case 7 no funciona."<<endl;
                            ifstream archivo;
                            string aux,a[9999];
	                        char aes[50],vacio[50];
	                        int cont = 0;
	                        archivo.open("Oracion Ingles.txt",ios::in);
	                        if (archivo.fail())
	                        {
	                        	cout<<"No se pudo abrir el archivo."<<endl;
	                        	exit(1);
	                        }
	                        while(!archivo.eof())
	                        {
	                        	getline(archivo,aux);
	                        }
	                        archivo.close();
	                        stringstream input_stringstream(aux);
	                        char delimitador = ' ';
                            while (getline(input_stringstream, aux, delimitador))
                            {
                                a[cont] = aux;
                                cont++;
                                //cout<<a[cont]<<"  hay algo aqui?   ";
                                //system("pause");
                            }
                            for (int i = 0;i<=cont;i++)
                            {
                                cout<<a[i]<<' '; // Aca seria la busqueda, el a[i] te va tirando palabra por palabra asi que siendo super simple seria algo como busqueda(a[i])
                                strcpy(aes,a[i].c_str());
                                //cout<<*aes<<" ";
                                //strcpy(aes,a[i].c_str());
                                strcpy(in,aes);
                                //cout<<es<<" es ";
                                //system("pause");
                                //listo=0;
                                traducir_ingles(&*raiz);
                                strcpy(in,vacio);
                                strcpy(aes,vacio);
                            }
                            cout<< "\n";
                            break;
                        }
			}

		}	while (opc !='9');

}





//-------------------------------------------------------------------------------------

//						    	Funcion Menu

//-------------------------------------------------------------------------------------

void menu()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"               TRADUCTOR INGLES - ESPANOL / ESPANOL INGLES                      "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  1. Agregar palabra al diccionario interno                     "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  2. Borrar palabra del diccionario interno                     "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  3. Consultar Palabra en Ingles                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  4. Consultar Palabra en Espanol                               "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  5. Listar Todas las Palabras                                  "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  6. Agregar palabras desde el .txt al dic. interno             "<<endl;
	cout<<"                                                                                "<<endl;
    cout<<"                  7. Traducir .txt Frase en Espanol a Ingles                    "<<endl;
	cout<<"                                                                                "<<endl;
    cout<<"                  8. Traducir .txt Frase en Ingles a Espanol                    "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  9. Salir                                                      "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"  Digite la Opcion (1 a 9):                                                     "<<endl;
}


//-------------------------------------------------------------------------------------
//						    	Funcion Menu Agregar
//-------------------------------------------------------------------------------------

void menu_agregar()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                      AGREGAR PALABRAS AL TRADUCTOR                             "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Buscar Ingles
//-------------------------------------------------------------------------------------

void menu_ingles()

{
	system("cls");

	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                         BUSCAR PALABRA EN INGLES                               "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}



//-------------------------------------------------------------------------------------
//						    	Funcion Menu Buscar Espanol
//-------------------------------------------------------------------------------------

void menu_espanol()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                        BUSCAR PALABRA EN ESPANOL                               "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}


//-------------------------------------------------------------------------------------
//						    	Funcion Menu Borrar
//-------------------------------------------------------------------------------------

void menu_borrar()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                      BORRAR PALABRA DEL DICCIONARIO                            "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Listar
//-------------------------------------------------------------------------------------

void menu_listar()

{

	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                      LISTAR PALABRAS DEL TRADUCTOR                             "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;

}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Escritura de frase
//-------------------------------------------------------------------------------------

void menu_frase()
{

	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                        INGRESAR LA FRASE A TRADUCIR                            "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;

}

//-------------------------------------------------------------------------------------
//  			    	Funcion Agregar palabras al Diccionario "interno"
//-------------------------------------------------------------------------------------

void agregar(ARBOL  *nodoarb)

{
	int det;
	if (*nodoarb == NULL){
		*nodoarb = new(Arbol);
		if (*nodoarb != NULL){
			strcpy((*nodoarb)->ingles,in);
			strcpy((*nodoarb)->espanol,es);
			(*nodoarb)->der=NULL;
			(*nodoarb)->izq=NULL;
		}
		else{
            system("cls");
			cout<<"¡No hay memoria suficiente! :(";
		}
	}
	else
	{
		det=strcmp(in,(*nodoarb)->ingles);
		if (det < 0)
			agregar (&((*nodoarb)->izq));
		else
			if (det > 0)
				agregar (&((*nodoarb)->der));
			else
			{
				//system("cls");
				cout<<"¡Dato duplicado!";
				system("pause");
				//system("cls");
			}
	}
}

//-------------------------------------------------------------------------------------
//  			    	Funciones para Agregar palabras al Diccionario usando el .txt
//-------------------------------------------------------------------------------------



//En el mentu, opcion 7, porque el C++ se pone mañoso si la pongo en otro lado, como aquí.



//-------------------------------------------------------------------------------------
//						    	Funcion Buscar Ingles
//-------------------------------------------------------------------------------------


void buscar_ingles(ARBOL nodoarb)

{

	if (nodoarb != NULL){

		buscar_ingles(nodoarb->izq);

		if (strcmp(in,nodoarb->ingles)==0)

		{
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"                        "<<nodoarb->ingles<<" -> "<<nodoarb->espanol<<endl;
			listo=1;
			return;
		}
		buscar_ingles(nodoarb->der);
	}
}


//-------------------------------------------------------------------------------------
//						    	Funcion Buscar Ingles
//-------------------------------------------------------------------------------------


void buscar_espanol(ARBOL nodoarb)

{
	if (nodoarb != NULL){
		buscar_espanol(nodoarb->izq);
		if (strcmp(es,nodoarb->espanol)==0)
		{
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"                        "<<nodoarb->espanol<<" -> "<<nodoarb->ingles<<endl;
			listo=1;
			return;
		}
		buscar_espanol(nodoarb->der);
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion listar Palabras
//-------------------------------------------------------------------------------------





void listar(ARBOL nodoarb)

{
	if (nodoarb != NULL){
		listar(nodoarb->izq);

		cout<<"                            "<<nodoarb->ingles<<" -> "<<nodoarb->espanol<<endl;

		listar(nodoarb->der);
	}
}


//-------------------------------------------------------------------------------------
//						    	Funcion rotacionddsimple
//-------------------------------------------------------------------------------------


void rotacionddsimple(ARBOL *nodoarb)

{
  ARBOL nda=NULL;
	nda=(*nodoarb)->der;
	(*nodoarb)->der=nda->izq;
	nda->izq=(*nodoarb);
	nda->Fe=0;
	(*nodoarb)->Fe=0;
}



//-------------------------------------------------------------------------------------
//						    	Funcion rotaciondidoble
//-------------------------------------------------------------------------------------


void rotaciondidoble(ARBOL *nodoarb)
{
  ARBOL nda1=NULL, nda2=NULL;
	nda1=(*nodoarb)->der;
	nda2=nda1->der;
	nda1->izq=nda2->der;
	nda2->der=nda1;
	(*nodoarb)->der=nda2->izq;
	nda2->izq=(*nodoarb);

	if (nda2->Fe == 1)
		(*nodoarb)->Fe=-1;

	else
		(*nodoarb)->Fe=0;

	if (nda2->Fe == -1)
		(*nodoarb)->Fe=1;

	else
		(*nodoarb)->Fe=0;

	nda2->Fe=0;
	(*nodoarb)=nda2;

}



//-------------------------------------------------------------------------------------
//						    	Funcion rotaciondd2
//-------------------------------------------------------------------------------------


void rotaciondd2(ARBOL *nodoarb)

{

  ARBOL nda=NULL;
	nda=(*nodoarb)->der;
	(*nodoarb)->der=nda->izq;
	nda->izq=(*nodoarb);
	nda->Fe=-1;
	(*nodoarb)->Fe=1;
	(*nodoarb)=nda;

}



//-------------------------------------------------------------------------------------
//						    	Funcion rotacionii2
//-------------------------------------------------------------------------------------



void rotacionii2(ARBOL *nodoarb)

{
    ARBOL nda=NULL;
	nda=(*nodoarb)->izq;
	(*nodoarb)->izq=nda->der;
	nda->der=(*nodoarb);
	nda->Fe=1;
	(*nodoarb)->Fe=-1;
	(*nodoarb)=nda;

}



//-------------------------------------------------------------------------------------
//						    	Funcion rotacionsimple
//-------------------------------------------------------------------------------------


void rotacioniisimple(ARBOL *nodoarb)

{

  ARBOL nda=NULL;
	nda=(*nodoarb)->izq;
	(*nodoarb)->izq=nda->der;
	nda->der=(*nodoarb);
	nda->Fe=0;
	(*nodoarb)->Fe=0;
        *nodoarb=nda;

}



//-------------------------------------------------------------------------------------
//						    	Funcion rotacioniddoble
//-------------------------------------------------------------------------------------



void rotacioniddoble(ARBOL *nodoarb)

{

  ARBOL nda1=NULL, nda2=NULL;

	nda1=(*nodoarb)->izq;
	nda2=nda1->der;
	nda1->der=nda2->izq;
	nda2->izq=nda1;

	(*nodoarb)->izq=nda2->der;
	nda2->der=(*nodoarb);

	if (nda2->Fe == 1)
		nda1->Fe=-1;

	else
		nda1->Fe=0;

	if (nda2->Fe == -1)
		(*nodoarb)->Fe=1;

	else
		(*nodoarb)->Fe=0;

	nda2->Fe=0;
	(*nodoarb)=nda2;

}



//-------------------------------------------------------------------------------------
//						    	Funcion Menor
//-------------------------------------------------------------------------------------



void menor(ARBOL nodoarb)

{

	if (nodoarb->izq == NULL)
	{
		strcpy(in,nodoarb->ingles);

		strcpy(es,nodoarb->espanol);
	}

	else
		menor(nodoarb->izq);

}



//-------------------------------------------------------------------------------------
//						    	Funcion Actualizarbi
//-------------------------------------------------------------------------------------



void actualizarbi(ARBOL *nodoarb, int *ban)

{

	switch((*nodoarb)->Fe){
		case -1:
			(*nodoarb)->Fe=0;

			break;

		case 0:
			(*nodoarb)->Fe=1;
			*ban=0;
			break;

		case 1:
			switch((*nodoarb)->der->Fe){
				case 1:
					rotacionddsimple(&(*nodoarb));
					break;

				case -1:
					rotaciondidoble(&(*nodoarb));
					break;

				case 0:
					rotaciondd2(&(*nodoarb));
					*ban=0;
					break;

			}
			break;

	}

}

//-------------------------------------------------------------------------------------
//						    	Funcion Actualizarbd
//-------------------------------------------------------------------------------------





void actualizarbd(ARBOL *nodoarb, int *ban)

{

	switch((*nodoarb)->Fe){

		case 1:
			(*nodoarb)->Fe=0;
			break;

		case 0:
			(*nodoarb)->Fe=-1;
			*ban=0;
			break;

		case -1:
			switch((*nodoarb)->izq->Fe){
				case -1:
					rotacioniisimple(&(*nodoarb));
					break;

				case 1:
					rotacioniddoble(&(*nodoarb));
					break;

				case 0:
					rotacionii2(&(*nodoarb));
					*ban=0;
					break;

			}

			break;

	}

}



//-------------------------------------------------------------------------------------
//						    	Funcion Eliminar
//-------------------------------------------------------------------------------------



void eliminar(ARBOL *nodoarb, int *ban)

{

 ARBOL aux=NULL;

	if ((*nodoarb)->izq == NULL){
		aux=*nodoarb;
		*nodoarb=(*nodoarb)->der;
		free(aux);
		*ban=1;

	}

	else{

		if ((*nodoarb)->der == NULL){
			aux=*nodoarb;
			*nodoarb=(*nodoarb)->izq;
			free(aux);
			*ban=1;

		}

		else{

			menor((*nodoarb)->der);
			borrar(&(*nodoarb)->der,&(*ban));
			if (*ban)
				actualizarbd(&(*nodoarb),&(*ban));

		}

	}

}



//-------------------------------------------------------------------------------------
//						    	Funcion Borrar
//-------------------------------------------------------------------------------------



void borrar(ARBOL *nodoarb , int *ban)

{
	if (nodoarb == NULL)
		*ban=0;

	else

		if (strcmp((*nodoarb)->ingles,in)==0)

			eliminar(&(*nodoarb),&(*ban));



		else

			if (strcmp((*nodoarb)->ingles,in) > 0 ){
				borrar(&(*nodoarb)->izq,&(*ban));

				if (*ban)
					actualizarbi(&(*nodoarb),&(*ban));

			}
			else{

				borrar(&(*nodoarb)->der,&(*ban));
				if (*ban)
					actualizarbd(&(*nodoarb),&(*ban));

			}

}



//-------------------------------------------------------------------------------------
//						    	Funciones de Escribir en .txt
//-------------------------------------------------------------------------------------


void escribir(char *x){
    ofstream archivo;
    archivo.open("Traduccion a Ingles.txt",ios::app);
    archivo<<x;
    archivo<<" ";
    cout<< "Palabra traducida escrita.\n";
	archivo.close();
}

void write(char *x){
    ofstream archivo;
    archivo.open("Traduccion a Espanol.txt",ios::app);
    archivo<<x;
    archivo<<" ";
    cout<< "Palabra traducida escrita.\n";
	archivo.close();
}

//-------------------------------------------------------------------------------------
//						    	Funciones de Leer Archivos
//-------------------------------------------------------------------------------------

//Estan en los case del menu, porque el c++ se pone mañoso con tanta identacion. al nivel en donde codigo que esta bueno deja de funcionar sin motivo aparente,
//me demoré como 3 dias en descubrirlo, asi que mejor se quedan en el menu.

//-------------------------------------------------------------------------------------
//						    	Funciones de Traducir Archivos
//-------------------------------------------------------------------------------------

void traducir_espanol(ARBOL nodoarb)
{
    char *escritura;
    //cout<<"por aqui";
    //system("pause");
	if (nodoarb != NULL){
		traducir_espanol(nodoarb->izq);
		if (strcmp(es,nodoarb->espanol)==0)
		{
		    escritura=nodoarb->ingles;
		    //cout<<"por aqui";
		    //system("pause");
			escribir(escritura);
			//listo=1;
			return;
		}

		traducir_espanol(nodoarb->der);
	}
}

void traducir_ingles(ARBOL nodoarb)
{
    char *escritura;
    //cout<<"por aqui ingles";
    //system("pause");
	if (nodoarb != NULL){
		traducir_ingles(nodoarb->der);
		if (strcmp(in,nodoarb->ingles)==0)
		{
		    escritura=nodoarb->espanol;
		    //cout<<"por aqui";
		    //system("pause");
			write(escritura);
			//listo=1;
			return;
		}

		traducir_ingles(nodoarb->izq);
	}
}


//-------------------------------------------------------------------------------------
//						               FIN
//-------------------------------------------------------------------------------------
