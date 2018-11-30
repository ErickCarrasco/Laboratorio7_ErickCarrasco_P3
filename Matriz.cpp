#include "Matriz.h"

Matriz::Matriz(){

}

Matriz::Matriz( string nombre, int** matriz, int size){
	this->nombre=nombre;
	this->matriz=matriz;
	this->size=size;
}

void Matriz::determinante(){
	if(size==2){
		det=matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0];
	}
}

Matriz Matriz::operator|(Matriz p_matrix){
	int** retMatrix = new int*[size];
	for (int i = 0; i < 2; ++i)
	{
		retMatrix[i]=new int[size];
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			retMatrix[i][j] = matriz[i][j] + p_matrix.getMatriz()[i][j];
		}
	}
	Matriz x("hola",retMatrix,2);
	return x;
}

int** Matriz::getMatriz(){
	return matriz;
}

