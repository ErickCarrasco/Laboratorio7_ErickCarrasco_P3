#include "Matriz.h"
#include <iostream>
#include <string>

#include <vector>

#include <sstream>

using namespace std;

//Provisiona una matrix de nxn enteros
int** createIntMatrix(int);

//Inicalizar una matrix de nxn enteros
void initIntMatrix(int** , int);

//Imprimir Una matrix de nxn enteros
void printIntMatrix(int** , int);

//Liberar una matrix de nxn enteros
void freeIntMatrix(int**& , int);

int main(){
	int value=1;
	vector <Matriz*> lista;

	while(value==1){
		cout<<"1/ Crear Matrix"<<endl;
		cout<<"2/ Listar Matrices"<<endl;
		cout<<"3/ Eliminar matrix"<<endl;
		cout<<"4/ Operador de matrices"<<endl;
		cout<<"5/ Salir"<<endl;
		cout<<"Seleccione: ";
		int seleccion;
		cin>>seleccion;
		cout<<endl;
		while(seleccion<0 || seleccion>5){
			cout<<"Ingreso una seleccion no valida "<<endl;

			cout<<"1/ Crear Matrix"<<endl;
			cout<<"2/ Listar Matrices"<<endl;
			cout<<"3/ Eliminar matrix"<<endl;
			cout<<"4/ Operador de matrices"<<endl;
			cout<<"5/ Salir"<<endl;
			cout<<"Seleccione: ";
			cin>>seleccion;
		}
		switch(seleccion){
			case 1:
			{
				cout<<"Bienvenido. Crear Matrix"<<endl;
				int size;
				cout<<"Ingrese el size de la matrix(2 o 3): "<<endl;
				cin>>size;
				while(size<2 || size>3){
					cout<<"Ingrese el size de la matrix(2 o 3): "<<endl;
					cin>>size;
				}
				string definer;
				cout<<"Ingrese un identificador para la matriz: "<<endl;
				cin>>definer;
				int** matrix = createIntMatrix(size);
				initIntMatrix(matrix, size);
				lista.push_back(new Matriz(definer,matrix, size));

			}
			break;

			case 2:
			{
				for (int i = 0; i < lista.size(); ++i){
					int num =lista.at(i)->getSize();
					printIntMatrix(lista.at(i)->getMatriz(), num);
				}
				/*
				Matriz x = *lista.at(0)|*lista.at(1);
				Matriz* x1 = &x;
				lista.push_back(x1);
				for (int i = 0; i < 2; ++i)
				{
					for (int j = 0; j < 2; ++j)
						{
							cout<<" "<<lista.at(2)->getMatriz()[i][j]<<endl;
						}	
				}
				*/

			}			
			break;

			case 3:
			{
				int pos;
				for (int i = 0; i < lista.size(); ++i){
					int num =lista.at(i)->getSize();
					printIntMatrix(lista.at(i)->getMatriz(), num);
				}
				cout<<endl;
				cout<<"Ingrese el numero de pos a borrar: "<<endl;
				cin>>pos;
				if(pos<0 || pos>lista.size()-1){
					cout<<"FUera del rango"<<endl;
				}else{
					lista.erase(lista.begin()+pos, lista.begin()+pos+1);
				}

				

			}
			break;

			case 4:
			{
				string cadena_user;
				cout<<"Ingrese un string para efecutar una operacion: "<<endl;
				cout<<"Ejemplo* A|B"<<endl;
				cin>>cadena_user;

				int count=0;
				int evaluador=0;
				char operador;
				for (int i = 0; i < cadena_user.size(); i++){
					if (cadena_user[i]=='|'){
						cout<<"Taking data"<<endl;
						operador=cadena_user[i];
						evaluador=count;
					}
					count++;
				}

				stringstream ip1;
				stringstream ip2;
				string nombre1;
				string nombre2;
				char ValueX;
				bool verify=true;
				for (int i = 0; i < cadena_user.size(); ++i)
				{
					if (cadena_user[i]=='|')
					{
						verify=false;
					}else{
						if (verify){
							ip1>>cadena_user[i];
						}else{
							ip2>>cadena_user[i];
						}
					}
				}
				nombre1=ip1.str();
				nombre2=ip2.str();

				cout<<endl;
				cout<<operador<<endl;

				if (operador=='|'){
					int m1;
					int m2;

					//for 1
					for (int i = 0; i < lista.size(); ++i)
					{
						if (lista.at(i)->getNombre()==nombre1){
							m1=i;
						}
					}

					//For 2
					for (int i = 0; i < lista.size(); ++i)
					{
						if (lista.at(i)->getNombre()==nombre2){
							m2=i;
						}
					}
				}

				bool verificador_sizes=false;

				if (lista.at(m1)->getSize()==lista.at(m2)->getSize()){
					verificador_sizes=true;
				}

				if (verificador_sizes){
					Matriz x = *lista.at(m1)|*lista.at(m2);
					Matriz* x1 = &x;
					lista.push_back(x1);
					for (int i = 0; i < 2; ++i)
					{
						for (int j = 0; j < 2; ++j)
						{
							cout<<" "<<lista.at(2)->getMatriz()[i][j]<<endl;
						}
						cout<<endl;	
					}

					cout<<endl;
				}


			}
			break;

			case 5:
			{
				value=1000;
			}
			break;


		}
	}
	return 0;
}

//Imprimir la matrix

void printIntMatrix(int** matrix, int size){
	for(int i =0; i<size; i++){
		for(int j =0; j<size; j++){
			cout<< " " << matrix[i][j];

		}
		cout<< endl;
	}
	cout<< endl;

}

//Liberar matrix

void freeIntMatrix(int**& matrix, int size){
	//Primero liberamos las columnas de cada fila
	for(int i =0; i<size; i++){
		delete[] matrix[i];
		matrix[i]=NULL;
	}
	//Liberar filas
	delete[]matrix;
	matrix = NULL;
}

//Inicializar la matrix

void initIntMatrix(int** matrix, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<"Ingrese un  numero para la posicion "<<i<<" , "<<j<<" :"<<endl;
			int numero;
			cin >>numero;
			matrix[i][j]=numero;
		}
	}
}

//provisionar la matrix

int** createIntMatrix(int size){
	int** retVal=NULL;
	
	//Provisionar las filas
	retVal = new int*[size];

	//Provisionar las columnas
	for(int i =0; i<size; i++){
		retVal[i]= new int[size];
	}

	return retVal;
}